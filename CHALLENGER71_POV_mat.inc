//wrap the file with the version
#local Temp_version = version;
#version 3.7;
//==================================================
//POV-Ray Materials list
//==================================================
//This file has been created by PoseRay v3.13.29.645
//3D model to POV-Ray/Moray Converter.
//Author: FlyerX
//Email: flyerx_2000@yahoo.com
//Web: https://sites.google.com/site/poseray/
//==================================================
//Files needed to run the POV-Ray scene:
//CHALLENGER71_POV_main.ini (initialization file - open this to render)
//CHALLENGER71_POV_scene.pov (scene setup of cameras, lights and geometry)
//CHALLENGER71_POV_geom.inc (geometry)
//CHALLENGER71_POV_mat.inc (materials)
//LICENSE.png
//LICENSE .png
//CHALLENG.png
//CHALLEN1.png
//DOORLINE.png
//DOORLIN1.png
//BOTTOM.png
//CHALLEN2.png
//CHALLEN3.png
//CHALLEN4.png
//BRAKDISC.png
//TIREBACK.png
//DRIVER.png
//ENGINE.png
//CHALLEN5.png
//CHALLEN6.png
//TIRE.png
//TIRE BUM.png
//CHALLEN7.png
// 
 
//Macros used by PoseRay to manipulate pigments
//October 06, 2010
//By FlyerX 

#macro pigment_fade(p1,f)
//filters a pigment by a value f. f=0 pigment is white, f=1 pigment is p1
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {(PR1(x,y,z).red-1)*f+1}
#local PR_FGrn=function (x,y,z) {(PR1(x,y,z).green-1)*f+1}
#local PR_FBlu=function (x,y,z) {(PR1(x,y,z).blue-1)*f+1}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 

#macro pigment_gray(p1)
//converts to grayscale using luminance
#local PR1 = function {pigment{p1}}
#local PR_Gray=function (x,y,z) {0.2126*PR1(x,y,z).red+0.7152*PR1(x,y,z).green+0.0722*PR1(x,y,z).blue}
function{PR_Gray(x,y,z)}
#end  

#macro pigment_multiply(p1,p2)
//multiplies two pigments p1xp2
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red*PR2(x,y,z).red}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green*PR2(x,y,z).green}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue*PR2(x,y,z).blue} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_screen(p1,p2)
//screens two pigments p1 p2
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {1-(1-PR1(x,y,z).red)*(1-PR2(x,y,z).red)}
#local PR_FGrn=function (x,y,z) {1-(1-PR1(x,y,z).green)*(1-PR2(x,y,z).green)}
#local PR_FBlu=function (x,y,z) {1-(1-PR1(x,y,z).blue)*(1-PR2(x,y,z).blue)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end        

#macro pigment_divide(p1,p2)
//divides pigment p2 by p1
//1/256 is added to the dividing color to prevent division by zero 
//colors are clipped to 0-1
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR2(x,y,z).red/(PR1(x,y,z).red+0.004),0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR2(x,y,z).green/(PR1(x,y,z).green+0.004),0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR2(x,y,z).blue/(PR1(x,y,z).blue+0.004),0,1)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end  


#macro pigment_add(p1,p2)
//adds two pigments - values are clipped 0 to 1
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR1(x,y,z).red+PR2(x,y,z).red,0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR1(x,y,z).green+PR2(x,y,z).green,0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR1(x,y,z).blue+PR2(x,y,z).blue,0,1)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 

#macro pigment_substract(p1,p2)
//subtracts two pigments - values are clipped 0 to 1
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR2(x,y,z).red-PR1(x,y,z).red,0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR2(x,y,z).green-PR1(x,y,z).green,0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR2(x,y,z).blue-PR1(x,y,z).blue,0,1)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end

#macro pigment_colorburn(p1,p2)
//burns p1 onto p2
//if image maps, they should be set to gamma 1 or it will give wrong results. 
//resulting image should be gamma corrected again using pigment_power(pigment,2.2)
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(1-((1-PR2(x,y,z).red)/(PR1(x,y,z).red+0.004)),0,1)}
#local PR_FGrn=function (x,y,z) {clip(1-((1-PR2(x,y,z).green)/(PR1(x,y,z).green+0.004)),0,1)}
#local PR_FBlu=function (x,y,z) {clip(1-((1-PR2(x,y,z).blue)/(PR1(x,y,z).blue+0.004)),0,1)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_linearburn(p1,p2)
//burns p1 onto p2
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {clip(PR2(x,y,z).red+PR1(x,y,z).red-1,0,1)}
#local PR_FGrn=function (x,y,z) {clip(PR2(x,y,z).green+PR1(x,y,z).green-1,0,1)}
#local PR_FBlu=function (x,y,z) {clip(PR2(x,y,z).blue+PR1(x,y,z).blue-1,0,1)} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_overlay(p1,p2)
//overlays p1 onto p2
//if image maps, they should be set to gamma 1 or it will give wrong results. 
//resulting image should be gamma corrected again using pigment_power(pigment,2.2)
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}


#local PR_FRed=function (x,y,z) {select((PR2(x,y,z).red-0.5),
clip(2*PR1(x,y,z).red*PR2(x,y,z).red,0,1),
clip(1-2*(1-PR1(x,y,z).red)*(1-PR2(x,y,z).red),0,1))}

#local PR_FGrn=function (x,y,z) {select((PR2(x,y,z).green-0.5),
clip(2*PR1(x,y,z).green*PR2(x,y,z).green,0,1),
clip(1-2*(1-PR1(x,y,z).green)*(1-PR2(x,y,z).green),0,1))}

#local PR_FBlu=function (x,y,z) {select((PR2(x,y,z).blue-0.5),
clip(2*PR1(x,y,z).blue*PR2(x,y,z).blue,0,1),
clip(1-2*(1-PR1(x,y,z).blue)*(1-PR2(x,y,z).blue),0,1))}

average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]  //add each color and then divide by 3
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]    
  }
#end 

#macro pigment_transmit(p1,tr)
//sets the transparency of p1 to tr
#local PR1 = function {pigment{p1}} 
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <1,0,0,0,tr/3>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,1,0,0,tr/3>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,0,1,0,tr/3>*3]}]   
  }
#end  

#macro pigment_process(p1,p2,tr)
//multiplies two pigments and sets the transparency to tr
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red*PR2(x,y,z).red}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green*PR2(x,y,z).green}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue*PR2(x,y,z).blue} 
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <1,0,0,0,tr/3>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,1,0,0,tr/3>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgbft <0,0,0,0,tr>][1 rgbft <0,0,1,0,tr/3>*3]}]    
  }
#end   



#macro pigment_power(p1,n)
//raises a pigment to a power - works with images with no mask (jpeg, bmp...)
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {pow(PR1(x,y,z).red,n)}
#local PR_FGrn=function (x,y,z) {pow(PR1(x,y,z).green,n)}
#local PR_FBlu=function (x,y,z) {pow(PR1(x,y,z).blue,n)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 


#macro pigment_threshold(p1,s)
//makes a pigment black if color < s or white otherwise
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {0.5*(sgn(PR1(x,y,z).red-s)+1)}
#local PR_FGrn=function (x,y,z) {0.5*(sgn(PR1(x,y,z).green-s)+1)}
#local PR_FBlu=function (x,y,z) {0.5*(sgn(PR1(x,y,z).blue-s)+1)}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end  


#macro pigment_invert(p1)
//inverts the color -> 1-RGB
#local PR1 = function {pigment{p1}}
#local PR_FRed=function (x,y,z) {1-PR1(x,y,z).red}
#local PR_FGrn=function (x,y,z) {1-PR1(x,y,z).green}
#local PR_FBlu=function (x,y,z) {1-PR1(x,y,z).blue}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end 

 

#macro pigment_mix(p1,p2,xv)
//mixes two pigments on a sliding scale xv from 0 to 1 
#local PR1 = function {pigment{p1}}
#local PR2 = function {pigment{p2}}
#local PR_FRed=function (x,y,z) {PR1(x,y,z).red*(1-xv)+PR2(x,y,z).red*xv}
#local PR_FGrn=function (x,y,z) {PR1(x,y,z).green*(1-xv)+PR2(x,y,z).green*xv}
#local PR_FBlu=function (x,y,z) {PR1(x,y,z).blue*(1-xv)+PR2(x,y,z).blue*xv}
average pigment_map{
    [function{PR_FRed(x,y,z)} color_map{[0 rgb 0][1 rgb <1,0,0>*3]}]
    [function{PR_FGrn(x,y,z)} color_map{[0 rgb 0][1 rgb <0,1,0>*3]}]
    [function{PR_FBlu(x,y,z)} color_map{[0 rgb 0][1 rgb <0,0,1>*3]}]
  }
#end

//=======================================

#macro power_ramp(xv,xa,xb,ya,yb,pw)
//generates a float with a power ramp from (xa,ya) to (xb,yb) with power pw and argument xv. 
//ramp slope is zero at xb
  ((ya-yb)/pow((xa-xb),pw))*pow((xv-xb),pw)+yb
#end

#macro power_ramp2(xv,xa,xb,ya,yb,pw)
//generates a float with a power ramp from (xa,ya) to (xb,yb) with power pw and argument xv. 
//ramp slope is zero at xa
  ((yb-ya)/pow((xb-xa),pw))*pow((xv-xa),pw)+ya
#end

#macro linear_ramp(xv,xa,xb,ya,yb)
//generates a linear float from (xa,ya) to (xb,yb)
  (yb-ya)/(xb-xa)*(xv-xa)+ya
#end
 
//==================================================
//Map definitions
#declare p_map1=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/LICENSE.png"   transmit all 0 } }
#declare p_map2=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/LICENSE .png" gamma 1.0  }}
#declare p_map3=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLENG.png"   transmit all 0 } }
#declare p_map4=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN1.png"   transmit all 0 } }
#declare p_map5=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/DOORLINE.png"   transmit all 0 } }
#declare p_map6=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/DOORLIN1.png" gamma 1.0  }}
#declare p_map7=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/BOTTOM.png"   transmit all 0 } }
#declare p_map8=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN2.png"   transmit all 0 } }
#declare p_map9=normal {bump_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN3.png"  }}
#declare p_map10=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN4.png" gamma 1.0  }}
#declare p_map11=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/BRAKDISC.png"   transmit all 0 } }
#declare p_map12=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/TIREBACK.png" gamma 1.0  }}
#declare p_map13=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/DRIVER.png"   transmit all 0 } }
#declare p_map14=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/ENGINE.png"   transmit all 0 } }
#declare p_map15=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN5.png"   transmit all 0 } }
#declare p_map16=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN6.png"   transmit all 0 } }
#declare p_map17=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/TIRE.png"   transmit all 0 } }
#declare p_map18=normal {bump_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/TIRE BUM.png"  }}
#declare p_map19=pigment {image_map{png "C:/Users/Alvaro/Desktop/FINAL-100363686/challenger/CHALLEN7.png"   transmit all 0 } }
 
//==================================================
//Material definitions
#declare License_=
#declare PR_DIFFUSE=pigment{p_map1}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map2 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Material__602_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome1_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__580_=
#declare PR_DIFFUSE=pigment{p_map4}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0364129215788742 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.60,0.93,0.59> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__600_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__601_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare DoorLine_=
#declare PR_DIFFUSE=pigment{p_map5}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map6 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Black_=
#declare PR_DIFFUSE=pigment {color srgb <0.00,0.00,0.00> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Bottom_=
#declare PR_DIFFUSE=pigment{p_map7}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome2_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc1_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Badging_Chrome_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Brake_Disc_=
#declare PR_DIFFUSE=pigment{p_map11}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map12 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Brake_Disc1_=
#declare PR_DIFFUSE=pigment{p_map11}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map12 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Brake_Pads_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare DoorLine1_=
#declare PR_DIFFUSE=pigment{p_map5}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map6 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Badging_Chrome1_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Badging_Chrome2_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare DoorLine2_=
#declare PR_DIFFUSE=pigment{p_map5}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map6 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Misc_Chrome3_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Badging_Chrome3_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Material__6021_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare DoorLine3_=
#declare PR_DIFFUSE=pigment{p_map5}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map6 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Badging_Chrome4_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Driver_=
#declare PR_DIFFUSE=pigment{p_map13}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0507914044212883 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__6022_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Engine_=
#declare PR_DIFFUSE=pigment{p_map14}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Engine_Chrome_=
#declare PR_DIFFUSE=pigment{p_map14}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Engine_Chrome1_=
#declare PR_DIFFUSE=pigment{p_map14}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Engine1_=
#declare PR_DIFFUSE=pigment{p_map14}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Badging_Chrome5_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Misc2_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome4_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__585_=
#declare PR_DIFFUSE=pigment{p_map15}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0100523625592439 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.61,0.98,0.59> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__586_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 50/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0340165059863374 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__6023_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare DoorLine5_=
#declare PR_DIFFUSE=pigment{p_map5}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map6 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Misc3_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome5_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Badging_Chrome6_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Interior_=
#declare PR_DIFFUSE=pigment{p_map16}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0651698944055736 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc4_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc5_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__588_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0220344351655245 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Badging_Chrome7_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Material__610_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome6_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Tire_=
#declare PR_DIFFUSE=pigment{p_map17}


#declare F1=finish{specular  1 //Max highlight intensity: 0 -> 1
                   roughness 0.0459985768071503 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.19,0.19,0.19> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map18
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__590_=
#declare PR_DIFFUSE=pigment{p_map19}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0292236765867316 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__5901_=
#declare PR_DIFFUSE=pigment{p_map19}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0292236765867316 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__5902_=
#declare PR_DIFFUSE=pigment{p_map19}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0292236765867316 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__5903_=
#declare PR_DIFFUSE=pigment{p_map19}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0292236765867316 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Tire_Back_=
#declare PR_DIFFUSE=pigment {color srgb <0.19,0.19,0.19> transmit 0/100 }


#declare F1=finish{specular  1 //Max highlight intensity: 0 -> 1
                   roughness 0.0699627184487761 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.19,0.19,0.19> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map12 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Material__594_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 72/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0316200903938006 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__595_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 60/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0507914044212883 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__611_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Bottom1_=
#declare PR_DIFFUSE=pigment{p_map7}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome7_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc6_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Badging_Chrome8_=
#declare PR_DIFFUSE=pigment{p_map8}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }

#declare N1=normal{p_map9
               bump_size 0.3//size of bump features at pure white. Can be positive or negative
              }

#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                        normal{uv_mapping N1 }
                    }

#declare T2=texture{    pigment{color rgbft<0,0,0,1,1>} 
                        finish{ambient 0}}

material{
         texture{/*uv_mapping*/ 
                 pigment_pattern{uv_mapping p_map10 }
                 texture_map{
                     [0 T2]
                     [1 T1]
                     }}
}
#declare Material__6024_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc7_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc8_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Bottom2_=
#declare PR_DIFFUSE=pigment{p_map7}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome8_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc9_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.055584235606362 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome9_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Material__6025_=
#declare PR_DIFFUSE=pigment {color srgb <0.58,0.58,0.58> transmit 0/100 }


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0388093336004755 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.58,0.58,0.58> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc10_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc11_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Bottom3_=
#declare PR_DIFFUSE=pigment{p_map7}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc_Chrome10_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0244308489725936 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
#declare Misc12_=
#declare PR_DIFFUSE=pigment{p_map3}


#declare F1=finish{specular  0.898039215686275 //Max highlight intensity: 0 -> 1
                   roughness 0.0843412048621258 //surface roughness: 0.0005 -> 1
                   phong  0 phong_size 0 //Phong specular disabled
                   
                   ambient <0,0,0> emission srgb <0.00,0.00,0.00> //ambient RGB color: 0->1 for each component
                   diffuse  0.6 
                   reflection{0 } conserve_energy //reflection amount: 0 -> 1
                   }


#declare T1=texture{
                   pigment{uv_mapping PR_DIFFUSE }
                            finish{F1}
                    }


material{
         texture{/*uv_mapping*/
                 T1
                }
}
 
//restore the version used outside this file
#version Temp_version;
//==================================================
