<?xml version="1.0"?>
<case codename="ArcaneTest" xml:lang="en" codeversion="1.0">
 <arcane>
   <title>Test MaterialHeat</title>
   <description>Test des ateriaux</description>
   <timeloop>MaterialHeatTestLoop</timeloop>
 </arcane>

 <arcane-post-processing>
   <output-period>5</output-period>
   <output>
    <variable>Temperature</variable>
    <variable>AllTemperatures</variable>
   </output>
 </arcane-post-processing>

 <meshes>
   <mesh>
     <generator name="Cartesian2D">
       <nb-part-x>2</nb-part-x>
       <nb-part-y>2</nb-part-y>
       <origin>0.0 0.0</origin>
       <x><n>40</n><length>1.2</length><progression>1.0</progression></x>
       <y><n>60</n><length>1.5</length><progression>1.0</progression></y>
     </generator>
   </mesh>
 </meshes>

 <arcane-load-balance>
   <active>true</active>
   <period>5</period>
   <max-imbalance>0.01</max-imbalance>
   <min-cpu-time>0</min-cpu-time>
   <partitioner name="MeshPartitionerTester" />
 </arcane-load-balance>

 <material-heat-test>
   <nb-iteration>15</nb-iteration>
   <modification-flags>15</modification-flags>
   <material>
     <name>MAT1</name>
   </material>
   <material>
     <name>MAT2</name>
   </material>

   <environment>
     <name>ENV1</name>
     <material>MAT1</material>
     <material>MAT2</material>
   </environment>

   <heat-object>
     <center>0.3 0.4 0.0</center>
     <velocity>0.02 0.04 0.0</velocity>
     <radius>0.18</radius>
     <material>ENV1_MAT1</material>
     <expected-final-temperature>912136.555848185</expected-final-temperature>
   </heat-object>
   <heat-object>
     <center>0.8 0.4 0.0</center>
     <velocity>-0.02 0.04 0.0</velocity>
     <radius>0.25</radius>
     <material>ENV1_MAT2</material>
     <expected-final-temperature>1958580.32652892</expected-final-temperature>
   </heat-object>

 </material-heat-test>

</case>
