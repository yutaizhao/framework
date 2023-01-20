//-----------------------------------------------------------------------------
// Copyright 2000-2022 CEA (www.cea.fr) IFPEN (www.ifpenergiesnouvelles.com)
// See the top-level COPYRIGHT file for details.
// SPDX-License-Identifier: Apache-2.0
//-----------------------------------------------------------------------------
﻿using System;
using System.Collections.Generic;
using Newtonsoft.Json;
using System.Xml.Serialization;

namespace Arcane.Axl.Xsd
{
  public partial class variablesVariable
  {
    public enum Property
    {
      NoDump,
      NoNeedSync,
      ExecutionDepend,
      SubDomainDepend,
      SubDomainPrivate,
      NoRestore,
      NoExchange,
      Persistant,
      NoReplicaSync,
      Undefined
    }
    [XmlIgnore]
    //! Nom qualifié (avec le namespace de la classe).
    public string QualifiedClassName { get; private set; }

    //! Nom du namespace dans lequel est définie la classe.
    string NamespaceName { get; set; }
    string ClassName { get; set; }

    public bool IsNoDump { get { return dumpSpecified ? !dump : true; } }

    public bool IsNoNeedSync { get { return needsyncSpecified ? !needsync : true; } }

    public bool IsExecutionDepend { get { return executiondependSpecified ? executiondepend : false; } }

    public bool IsSubDomainDepend { get { return subdomaindependSpecified ? subdomaindepend : false; } }

    public bool IsSubDomainPrivate { get { return subdomainprivateSpecified ? subdomainprivate : false; } }

    public bool IsNoExchange { get { return noexchangeFieldSpecified ? noexchange : false; } }

    public bool IsPersistant { get { return persistantFieldSpecified ? persistant : false; } }

    public bool IsNoReplicaSync { get { return noreplicasyncFieldSpecified ? noreplicasync : false; } }

    public bool IsInFlow { get { return flow == Flow.@in; } }

    //! Indique si la variable est une variable sur un matériau (CEA only)
    public bool IsMaterial {
      get {
        return materialSpecified ? material : false;
      }
    }
    //! Indique si la variable est une variable sur un milieu (CEA only)
    public bool IsEnvironment {
      get {
        return environmentSpecified ? environment : false;
      }
    }
    public bool IsNoRestore {
      get {
        if (GlobalContext.Instance.NoRestore == true) {
          return true;
        } else {
          return norestoreSpecified ? norestore : false;
        }
      }
    }

    public int NbProperty {
      get {
        return Convert.ToInt32(IsNoDump)
          + Convert.ToInt32(IsNoNeedSync)
          + Convert.ToInt32(IsExecutionDepend)
          + Convert.ToInt32(IsSubDomainDepend)
          + Convert.ToInt32(IsSubDomainPrivate)
          + Convert.ToInt32(IsNoRestore);
      }
    }

    public Property FirstProperty {
      get {
        if (IsNoDump)
          return Property.NoDump;
        if (IsNoNeedSync)
          return Property.NoNeedSync;
        if (IsExecutionDepend)
          return Property.ExecutionDepend;
        if (IsSubDomainDepend)
          return Property.SubDomainDepend;
        if (IsSubDomainPrivate)
          return Property.SubDomainPrivate;
        if (IsNoRestore)
          return Property.NoRestore;
        if (IsNoExchange)
          return Property.NoExchange;
        if (IsPersistant)
          return Property.Persistant;
        if (IsNoReplicaSync)
          return Property.NoReplicaSync;
        return Property.Undefined;
      }
    }
    [JsonIgnore()]
    public IEnumerable<Property> OthersProperties {
      get {
        var properties = new List<Property> ();
        if (IsNoDump)
          properties.Add (Property.NoDump);
        if (IsNoNeedSync)
          properties.Add (Property.NoNeedSync);
        if (IsExecutionDepend)
          properties.Add (Property.ExecutionDepend);
        if (IsSubDomainDepend)
          properties.Add (Property.SubDomainDepend);
        if (IsSubDomainPrivate)
          properties.Add (Property.SubDomainPrivate);
        if (IsNoRestore)
          properties.Add (Property.NoRestore);
        if (IsNoExchange)
          properties.Add (Property.NoExchange);
        if (IsPersistant)
          properties.Add (Property.Persistant);
        if (IsNoReplicaSync)
          properties.Add (Property.NoReplicaSync);
        properties.RemoveAt (0);
        return properties;
      }
    }

    public string FamilyName { get { return familyname; } }

    public bool HasFamilyName { get { return !String.IsNullOrEmpty (FamilyName); } }

    public bool HasShapeDim { get { return !String.IsNullOrEmpty(shapedim); } }

    public void InitializeAndValidate ()
    {
      // Vérifie que 'family-name' existe pour une variables sur les particules et les DoF.
      // et qu'il est absent pour les autres types de variable.
      if (itemkind == ItemKind.particle && !HasFamilyName)
        _ThrowInvalid("missing 'family-name' attribute for 'particle' variable");
      if (itemkind == ItemKind.dof && !HasFamilyName)
        _ThrowInvalid("missing 'family-name' attribute for 'dof' variable");
      if (HasFamilyName && (itemkind != ItemKind.particle && itemkind != ItemKind.dof))
        _ThrowInvalid("'family-name' attribute is valid only for 'particle' or 'dof' variables");

      // Vérifie que pour les variables matériaux ou milieux sont uniquement sur les mailles
      if ((IsMaterial || IsEnvironment) && itemkind != ItemKind.cell)
        _ThrowInvalid("material or environment variables are only valid with 'item-kind==cell'");

      if (HasShapeDim) {
        if (itemkind == ItemKind.none)
          _ThrowInvalid("'shape-dim' is only valid for variables on mesh");
        if (dim != "1")
          _ThrowInvalid("'shape-dim' is only valid for variables with 'dim'==1");
        if (IsMaterial || IsEnvironment)
          _ThrowInvalid("'shape-dim' is invalid if 'environment'==true or 'material'==true");
        if (datatype != DataType.real2 && datatype != DataType.real3 &&
            datatype != DataType.real2x2 && datatype != DataType.real3x3 && datatype != DataType.real)
          _ThrowInvalid($"Invalid datatype '{datatype}'. Valid values are 'real', 'real2', 'real3', 'real2x2' or 'real3x3'");
      }

      _Initialize();
    }

    void _Initialize()
    {
      NamespaceName = _ComputeNamespaceName();
      ClassName = _ComputeClassName();
      QualifiedClassName = _ComputeQualifiedClassName();
    }

    void _ThrowInvalid (string msg)
    {
      var full_msg = String.Format ("{0} (name={1} field-name={2}) ", msg, this.name, this.fieldname);
      throw new ApplicationException (full_msg);
    }

    string _ComputeNamespaceName()
    {
      if (IsMaterial || IsEnvironment)
        return "Arcane::Materials";
      return "Arcane";
    }
    string _ComputeClassNameWithShape()
    {
      string md_var_name = "";
      string item_kind = "Arcane::" + itemkind.Name();
      string static_shape = "";
      if (datatype == DataType.real2){
        static_shape = "2,";
        md_var_name = "Vector";
      }
      else if (datatype == DataType.real3){
        static_shape = "3,";
        md_var_name = "Vector";
      }
      else if (datatype == DataType.real2x2){
        static_shape = "2,2,";
        md_var_name = "Matrix";
      }
      else if (datatype == DataType.real3x3){
        static_shape = "3,3,";
        md_var_name = "Matrix";
      }
      else if (datatype==DataType.real){
      }
      else
        _ThrowInvalid($"Invalid datatype '{datatype}'. Valid values are 'real', 'real2', 'real3', 'real2x2' or 'real3x3'");
      return $"Mesh{md_var_name}MDVariableRefT<{item_kind},Arcane::Real,{static_shape}Arcane::MDDim{shapedim}>";
    }

    string _ComputeClassName()
    {
      if (!String.IsNullOrEmpty(shapedim))
        return _ComputeClassNameWithShape();
      string datatype_name = datatype.Name();
      if (datatypeField == DataType.@bool)
        datatype_name = "Byte";
      string xname = "Variable";
      if (IsMaterial)
        xname = "Material" + xname;
      if (IsEnvironment)
        xname = "Environment" + xname;
      if (itemkind != ItemKind.none)
        xname += itemkind.Name();
      switch (int.Parse(dim)) {
        case 0:
          if (itemkind == ItemKind.none)
            xname += "Scalar";
          break;
        case 1:
          xname += "Array";
          break;
        case 2:
          xname += "Array2";
          break;
      }
      xname += datatype_name;
      return xname;
    }

    string _ComputeQualifiedClassName()
    {
      // Si l'axl contient un nom de type spécifique alors on utilise celui là.
      if (!String.IsNullOrEmpty(internalcpptypename))
        return internalcpptypename;
      string ns = NamespaceName;
      string n = ClassName;
      if (!string.IsNullOrEmpty (ns))
        return ns + "::" + n;
      return n;
    }
  }
}

