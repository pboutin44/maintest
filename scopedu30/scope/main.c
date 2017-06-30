//#include <stdio.h>
//#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include <GLUT/glut.h>
#include <OpenGL/glu.h>
#include <unistd.h>
#include <stdio.h> 
#include <stdlib.h>

//#include <glm/glm.hpp>
//using namespace glm;
int main(){
	/*if( !glfwInit() )
	{
		    fprintf( stderr, "Failed to initialize GLFW\n" );
			    return -1;
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // We want OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // To make MacOS happy; should not be needed
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); //We don't want the old OpenGL 

	// Open a window and create its OpenGL context
	 GLFWwindow* window; // (In the accompanying source code, this variable is global)
	 window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL); */

	glfwInit();
	if( !glfwInit() ) 
	{ 
   		 fprintf( stderr, "Failed to initialize GLFW\n" ); 
   		 return -1; 
	}
	glfwWindowHint(GLFW_SAMPLES, 4); // antialiasing 4x 
	glfwOpenWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // Nous voulons OpenGL 3.3 
	glfwOpenWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3); 
	glfwOpenWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE); // Nous ne voulons pas de support de l'ancien OpenGL
 
	// Ouvre une fenêtre et crée son contexte OpenGL
	GLFWwindow* window; // (Dans le code joint, cette variable est globale) 
	window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL); 

	//	glfwiindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	//	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//	GLFWwindow *window = glfwCreateWindow(800, 800, "Mon titre", NULL, NULL);
	//if (!window->win)
	//	return (init_error("Failed to create GLFW window\n"));
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;

	 /*if( window == NULL ){
	     fprintf( stderr, "Failed to open GLFW window. If you have an Intel GPU, they are not 3.3 compatible. Try the 2.1 version of the tutorials.\n" );
	         glfwTerminate();
	             return -1;
	             }
	             glfwMakeContextCurrent(window); // Initialize GLEW
	             glewExperimental=1; // Needed in core profile
	             if (glewInit() != GLEW_OK) {
	                 fprintf(stderr, "Failed to initialize GLEW\n");
	                     return -1;
	                     }
				 // Ensure we can capture the escape key being pressed below
				  glfwSetInputMode(window, GLFW_STICKY_KEYS, GL_TRUE);
				 
				  do{
				      // Draw nothing, see you in tutorial 2 !
				 
				          // Swap buffers
				              glfwSwapBuffers(window);
				                  glfwPollEvents();
				 
				                  } // Check if the ESC key was pressed or the window was closed
				                  while( glfwGetKey(window, GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
				                  glfwWindowShouldClose(window) == 0 );
	*/
	 sleep(10);
	 return (0);
}
