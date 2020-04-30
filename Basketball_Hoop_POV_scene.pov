//wrap the file with the version
#local Temp_version = version;
#version 3.7;
//==================================================
//POV-Ray Main scene file
//==================================================
//This file has been created by PoseRay v3.13.29.645
//3D model to POV-Ray/Moray Converter.
//Author: FlyerX
//Email: flyerx_2000@yahoo.com
//Web: https://sites.google.com/site/poseray/
//==================================================
//Files needed to run the POV-Ray scene:
//Basketball_Hoop_POV_main.ini (initialization file - open this to render)
//Basketball_Hoop_POV_scene.pov (scene setup of cameras, lights and geometry)
//Basketball_Hoop_POV_geom.inc (geometry)
//Basketball_Hoop_POV_mat.inc (materials)
// 
//==================================================
//Model Statistics:
//Number of triangular faces..... 1812
//Number of vertices............. 1060
//Number of normals.............. 2844
//Number of UV coordinates....... 0
//Number of lines................ 0
//Number of materials............ 4
//Number of groups/meshes........ 3
//Number of subdivision faces.... 0
//Bounding Box....... from x,y,z=(-0.990599989891052,7.776254244557E-18,-0.22860012948513)
//                      to x,y,z=(0.990599989891052,3.96239924430847,0.723902940750122)
//                 size dx,dy,dz=(1.9811999797821,3.96239924430847,0.952503070235253)
//                  center x,y,z=(0,1.98119962215424,0.247651405632496)
//                       diagonal 4.5313379072844
//Surface area................... 7.5558145886972
//             Smallest face area 2.49983999027794E-6
//              Largest face area 0.975481789688189
//Memory allocated for geometry: 226 KBytes
// 
//==================================================
//IMPORTANT:
//This file was designed to run with the following command line options: 
// +W320 +H315 +FN +AM2 +A0.1 +r3 +Q9 +C -UA +MV3.7
//if you are not using an INI file copy and paste the text above to the command line box before rendering
 
#include "rad_def.inc"
 
global_settings {
  //This setting is for alpha transparency to work properly.
  //Increase by a small amount if transparent areas appear dark.
   max_trace_level 15
   assumed_gamma 1
 
   #local p_start=64/max(image_width,image_height);
   #local p_end_final=1/max(image_width,image_height);
radiosity {
     pretrace_start p_start
     pretrace_end   p_end_final
     count 800
     nearest_count 5
     error_bound 0.5
     recursion_limit 1
     low_error_factor .5
     gray_threshold 0.0
     minimum_reuse 0.015
     brightness 1
     adc_bailout 0.01/2
}
}
#include "Basketball_Hoop_POV_geom.inc" //Geometry
 
//CAMERA PoseRayCAMERA
camera {
        perspective
        up <0,1,0>
        right -x*image_width/image_height
        location <0,4.21884749357559E-15,9.06267581456879>
        look_at <0,4.21884749357559E-15,8.06267581456879>
        angle 25.3496789954331 // horizontal FOV angle
        rotate <0,0,0> //roll
        rotate <-25,0,0> //pitch
        rotate <0,45,0> //yaw
        translate <0,1.98119962215424,0.247651405632496>
        }
 
//PoseRay default Light attached to the camera
light_source {
              <0,4.21884749357559E-15,9.06267581456879> //light position
              color rgb <1,1,1>*1.6
              parallel
              point_at <0,4.21884749357559E-15,0>
              rotate <0,0,0> //roll
              rotate <-25,0,0> //elevation
              rotate <0,45,0> //rotation
             }
 
//Background
background { color srgb 0.35  }
 
//Assembled object that is contained in Basketball_Hoop_POV_geom.inc with no SSLT components
object{
      Basketball_Hoop_
      }  

#include "10487_basketball_v1_3dmax2011_it2_POV_geom.inc" //Geometry

//Assembled object that is contained in 10487_basketball_v1_3dmax2011_it2_POV_geom.inc with no SSLT components
object{
      _10487_basketball_v1_3dmax2011_it2_
      scale 0.01
      }    


 
//restore the version used outside this file
#version Temp_version;
//==================================================
