
#include <GL/glew.h>
//#include <glad/glad.h>
#include <OpenGL/gl.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <stdlib.h>
//#include "linmath.h"


int main(void)
{
    GLFWwindow* window;

    /* Initialize the library */
    if (!glfwInit())
        return -1;

    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(1024, 768, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);

    /* Loop until the user closes the window */
    while (!glfwWindowShouldClose(window))
    {
        /* Render here */
        glClear(GL_COLOR_BUFFER_BIT);

        /* Swap front and back buffers */
        glfwSwapBuffers(window);

        /* Poll for and process events */
        glfwPollEvents();
    }

    glfwTerminate();
	GLuint VertexArrayID; 
	glGenVertexArrays(1, &VertexArrayID); 
	glBindVertexArray(VertexArrayID);
	static const GLfloat g_vertex_buffer_data[] = { 
		   -1.0f, -1.0f, 0.0f, 
		      1.0f, -1.0f, 0.0f, 
			     0.0f,  1.0f, 0.0f, 
	};

//	 Ceci identifiera notre tampon de sommets
	 GLuint vertexbuffer; 
	  
	  // Génère un tampon et place l'identifiant dans 'vertexbuffer'
	  glGenBuffers(1, &vertexbuffer); 
	   
	   // Les commandes suivantes vont parler de notre tampon 'vertexbuffer'
	   glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
	    
	    // Fournit les sommets à OpenGL.
	    glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
	glEnableVertexAttribArray(0); 
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer); 
	glVertexAttribPointer( 
 	  0,                  // attribut 0. Aucune raison particulière pour 0, mais cela doit correspondre au « layout » dans le shader 
 	  3,                  // taille
  	 GL_FLOAT,           // type 
  	 GL_FALSE,           // normalisé ? 
  	 0,                  // nombre d'octets séparant deux sommets dans le tampon
  	 (void*)0            // décalage du tableau de tampon
	); 
 
// Dessine le triangle ! 
	glDrawArrays(GL_TRIANGLES, 0, 3); // Démarre à partir du sommet 0; 3 sommets au total -> 1 triangle 
 
	glDisableVertexAttribArray(0);




//GLfloat light_diffuse[] = {1.0, 0.0, 0.0, 1.0};  /* Red diffuse light. */
//GLfloat light_position[] = {1.0, 1.0, 1.0, 0.0};
	//	GLunit VertexArrayID;
//	GLuint vertexbuffer;
//	int tout; 
//	tout = 4545;
//	vertexbuffer = &tout;
	// Generate 1 buffer, put the resulting identifier in vertexbuffer
//	glGenBuffers(1, &vertexbuffer);
	// The following commands will talk about our 'vertexbuffer' buffer
//	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	// Give our vertices to OpenGL.
//	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);
   	 return 0;
}
