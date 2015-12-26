#version 410 core



// simple3d.vsh - A simplistic vertex shader that illustrates ONE WAY
//                to handle transformations along with a simple 3D
//                lighting model.

// Naming convention for variables holding coordinates:
// mc - model coordinates
// ec - eye coordinates
// lds - logical device space
// "p_" prefix on any of the preceding indicates the coordinates have been
//      embedded in projective space
// (gl_Position would be called something like: p_ldsPosition)

const int MAX_NUM_LIGHTS = 3;
uniform vec4 p_ecLightPos[MAX_NUM_LIGHTS];
uniform vec3 lightStrength[MAX_NUM_LIGHTS];
uniform vec3 globalAmbient;
uniform vec3 ka, kd, ks;
uniform float m;




// Transformation Matrices
uniform mat4 mc_ec =   // (dynamic rotations) * (ViewOrientation(E,C,up))
	mat4(1.0, 0.0, 0.0, 0.0, // initialize to identity matrix
	     0.0, 1.0, 0.0, 0.0, // ==> no dynamic rotations -AND- MC = EC
	     0.0, 0.0, 1.0, 0.0,
	     0.0, 0.0, 0.0, 1.0);
uniform mat4 ec_lds = // (W-V map) * (projection matrix)
	mat4(1.0, 0.0, 0.0, 0.0, // initialize to (almost) identity matrix
	     0.0, 1.0, 0.0, 0.0, // ==> ORTHOGONAL projection -AND- EC = LDS
	     0.0, 0.0, -1.0, 0.0,
	     0.0, 0.0, 0.0, 1.0);




// Per-vertex attributes
// 1. incoming vertex position in model coordinates
layout (location = 0) in vec3 mcPosition;
// 2. incoming vertex normal vector in model coordinates
in vec3 mcNormal; // incoming normal vector in model coordinates

out vec3 colorToFS;

vec3 evaluateLightingModel(in vec3 ec_Q, in vec3 ec_nHat)
{
	// Simplistic lighting model:
	// Reflected color will be a function of angle between the normal
	// vector and the light source direction. Specifically:


    vec3 finalColor = vec3(0.0, 0.0, 0.0);

    for (int i=0;i<MAX_NUM_LIGHTS;i++)
    {
       vec3 L;
			 if(p_ecLightPos[i][3] == 1.0)
				L = normalize(p_ecLightPos[i].xyz-ec_Q);
				else
				L = normalize(p_ecLightPos[i].xyz);

       vec3 E = normalize(-ec_Q); // we are in Eye Coordinates, so EyePos is (0,0,0)
       vec3 R = normalize(-reflect(L,ec_nHat));

       //calculate Ambient Term:
       vec3 Iamb = lightStrength[i];//Li
       //calculate Diffuse Term:
       vec3 Idiff = kd * max(dot(ec_nHat,L), 0.0);//(kd*n.li)
       Idiff = clamp(Idiff, 0.0, 1.0);

       // calculate Specular Term:
       vec3 Ispec = ks * pow(max(dot(R,E),0.0),m);//ks*(ri.v)^m
       Ispec = clamp(Ispec, 0.0, 1.0);

       finalColor += Iamb * Idiff + Ispec;//



    }
		vec3 result;

		result = (ka*globalAmbient)+finalColor;//ka*La+ sum


		//actor = dot(normalize(p_ecLightPos.xyz), -ec_nHat);

	return result;
}

void main ()
{
	// convert current vertex and its associated normal to eye coordinates
	vec4 p_ecPosition = mc_ec * vec4(mcPosition, 1.0);
	mat3 normalMatrix = transpose( inverse( mat3x3(mc_ec) ) );
	vec3 ec_nHat = normalize(normalMatrix * mcNormal);

	colorToFS = evaluateLightingModel(p_ecPosition.xyz, ec_nHat);

	// apply the projection matrix to compute the projective space representation
	// of the 3D logical device space coordinates of the input vertex:
	gl_Position = ec_lds * p_ecPosition;
}
