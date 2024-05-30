<?xml version="1.0"?>
<case codename="ArcaneTest" xml:lang="en" codeversion="1.0">
 <arcane>
   <title>Test MaterialHeat</title>
   <description>Test des Materiaux</description>
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
       <x><n>80</n><length>1.2</length><progression>1.0</progression></x>
       <y><n>120</n><length>1.5</length><progression>1.0</progression></y>
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
   <modification-flags>7</modification-flags>
   <check-numerical-result>true</check-numerical-result>
   <material>
     <name>MAT1</name>
   </material>
   <material>
     <name>MAT2</name>
   </material>
   <material>
     <name>MAT3</name>
   </material>

   <environment>
     <name>ENV1</name>
     <material>MAT1</material>
     <material>MAT2</material>
   </environment>
   <environment>
     <name>ENV2</name>
     <material>MAT2</material>
     <material>MAT3</material>
   </environment>

   <heat-object>
     <center>0.3 0.4 0.0</center>
     <velocity>0.02 0.04 0.0</velocity>
     <radius>0.18</radius>
     <material>ENV1_MAT1</material>
     <expected-final-temperature>3632937.10322508</expected-final-temperature>
   </heat-object>
   <heat-object>
     <center>0.8 0.4 0.0</center>
     <velocity>-0.02 0.04 0.0</velocity>
     <radius>0.25</radius>
     <material>ENV1_MAT2</material>
     <expected-final-temperature>7811591.27514109</expected-final-temperature>
   </heat-object>
   <heat-object>
     <center>0.2 1.2 0.0</center>
     <velocity>0.02 -0.05 0.0</velocity>
     <radius>0.2</radius>
     <material>ENV2_MAT2</material>
     <expected-final-temperature>4275505.39778122</expected-final-temperature>
   </heat-object>
   <heat-object>
     <center>0.9 0.9 0.0</center>
     <velocity>-0.02 -0.04 0.0</velocity>
     <radius>0.15</radius>
     <material>ENV2_MAT3</material>
     <expected-final-temperature>2302747.97123847</expected-final-temperature>
   </heat-object>

 </material-heat-test>

</case>
