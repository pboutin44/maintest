#include "scope.h"

int main(int argc, char *argv[]){
	GLFWwindow *window = NULL;
	const GLubyte *renderer;
	const GLubyte *version;
	GLuint vao;
	GLuint vbo;
	float width = 1640;
	float height = 1480;
	bool	textura;
/*assert (restart_gl_log ());
	// start GL context and O/S window using the GLFW helper library
	gl_log ("starting GLFW\n%s\n", glfwGetVersionString ());
	// register the error call-back function that we wrote, above
	glfwSetErrorCallback (glfw_error_callback);
	if (!glfwInit ()) {
	fprintf (stderr, "ERROR: could not start GLFW3\n");
	return 1;
	}*/
	/* geometry to use. these are 3 xyz points (9 floats total) to make a
		 triangle */
float	points[18];
//points = (float *)malloc(18 * sizeof(float));
points[0] = 0.0;
points[1] = 1.0;
points[2] = 0.0;
points[3] = 0.0;
points[4] = 0.0;
points[5] = 0.0;
points[6] = 1.0;
points[7] = 0.0;
points[8] = -0.5;
points[9] = 1.0;
points[10] = 0.0;
points[11] = -0.5;
points[12] = 1.0;
points[13] = 1.0;
points[14] = -0.5;
points[15] = 0.0;
points[16] = 1.0;
points[17] = 0.0;

/*0.0f, 1.0f,
0.0f, 0.0f,
1.0, 0.0,
1.0, 0.0,
1.0, 1.0,
0.0, 1.0*/
/*	float points[] = {
  0.232406, -0.745504, 1.477731,
 0.232406, -0.745504, 2.843098,
 -0.227475, -0.745504, 2.843098,
 0.232406, -0.745504, 2.843098,
 -0.227475, -0.745504, 2.843098,
 -0.227475, -0.745504, 1.477731,
	   };*/
/*
int g = 0;
   while(g  < 18)
{
    printf("\ndigits%d : %f", g, points[g]);
    g++;
}*/

/*float matrix[] = { 
 1.0f, 0.0f, 0.0f, 0.0f,
 0.0f, -0.422f, 0.906f, 0.0f,
 0.0f, -0.906f, -0.422f, 0.0f,
 0.0f, 0.0f, 0.0f, 1.0f
};*/
float	*matrix;
matrix = (float *)malloc(16 * sizeof(float));
matrix[0] = 0.707;
matrix[1] = 0.0;
matrix[2] = -0.707;
matrix[3] = 0.0;
matrix[4] = 0.0;
matrix[5] = 1.0;
matrix[6] = 0.0;
matrix[7] = 0.0;
matrix[8] = 0.707;
matrix[9] = 0.0;
matrix[10] = 0.707;
matrix[11] = 0.0;
matrix[12] = 0.0;
matrix[13] = 0.0;
matrix[14] = -1.414;
matrix[15] = 1.0;

float	*matrix6;
matrix6 = (float *)malloc(16 * sizeof(float));
matrix6[0] = 0.707;
matrix6[1] = 0.0;
matrix6[2] = -0.707;
matrix6[3] = 0.0;
matrix6[4] = 0.0;
matrix6[5] = 1.0;
matrix6[6] = 0.0;
matrix6[7] = 0.0;
matrix6[8] = 0.707;
matrix6[9] = 0.0;
matrix6[10] = 0.707;
matrix6[11] = 0.0;
matrix6[12] = 0.0;
matrix6[13] = 0.0;
matrix6[14] = -1.414;
matrix6[15] = 1.0;

float	*matrix7;
matrix7 = (float *)malloc(16 * sizeof(float));
matrix7[0] = 1.0;
matrix7[1] = 0.0;
matrix7[2] = 0.0;
matrix7[3] = 0.0;
matrix7[4] = 0.0;
matrix7[5] = 1.0;
matrix7[6] = 0.0;
matrix7[7] = 0.0;
matrix7[8] = 0.0;
matrix7[9] = 0.0;
matrix7[10] = 1.0;
matrix7[11] = 0.0;
matrix7[12] = 0.0;
matrix7[13] = 0.0;
matrix7[14] = 0.0;
matrix7[15] = 1.0;
//printf("sin(45) = %f", sin(45));
float	*matrix1;
matrix1 = (float *)malloc(16 * sizeof(float));
matrix1[0] = 1.0;
matrix1[1] = 0.0;
matrix1[2] = 0.0;
matrix1[3] = 0.0;
matrix1[4] = 0.0;
matrix1[5] = 1.0;
matrix1[6] = 0.0;
matrix1[7] = 0.0;
matrix1[8] = 0.0;
matrix1[9] = 0.0;
matrix1[10] = 1.0;
matrix1[11] = 0.0;
matrix1[12] = 0.0;
matrix1[13] = 0.0;
matrix1[14] = 0.0;
matrix1[15] = 1.0;

float	*matrix2;
matrix2 = (float *)malloc(16 * sizeof(float));
matrix2[0] = 1.0;
matrix2[1] = 0.0;
matrix2[2] = 0.0;
matrix2[3] = 0.0;
matrix2[4] = 0.0;
matrix2[5] = 1.0;
matrix2[6] = 0.0;
matrix2[7] = 0.0;
matrix2[8] = 0.0;
matrix2[9] = 0.0;
matrix2[10] = 1.0;
matrix2[11] = 0.0;
matrix2[12] = -0.5;
matrix2[13] = 0.0;
matrix2[14] = 0.0;
matrix2[15] = 1.0;

/* float colours[] = {
 1.0f, 0.0f, 0.0f,
 0.0f, 1.0f, 0.0f,
 0.0f, 0.0f, 1.0f,
 1.0f, 0.0f, 0.0f,
 0.0f, 1.0f, 0.0f,
 0.0f, 0.0f, 1.0f
};*/

float *matrix3;
matrix3 = (float *)malloc(16 * sizeof(float));
matrix3 = produit_matricielle4(matrix, matrix1, 1.0);

float		l = 0.0;
int			nb_tr;

float	*str56;
float	str65[56880];
//float	*tmp;
float	texcoords[56880];
float	colours[56880];
int		h;
int		d;
//int		z;
h = 0;
str56 = point(argv[1]);
while(str56[h] != 88888888)
{
	h++;
}
nb_tr = 56900;

if(h < 56820)
{
//	puts("tartiflette");
	l = 0.5;
	nb_tr = 77;
}

float	*matrix8;
matrix8 = (float *)malloc(16 * sizeof(float));
matrix8 = matrix_y( 0, l); 

printf("sizeof : %d", h);
//tmp = (float *)malloc(456 *sizeof(float));
d = 0;
int m = 0;
int a = 0;
while(str56[d] != 88888888)
{
	str65[d] = str56[d];
//	if((d + 1) % 3 != 0)
//	{
		texcoords[m] = str56[d];
		m++;
//	}
	if( a > 2)
	{
		a = 0;
	}
	if(a == 0)
	{
	if((d + 1) % 3 == 1)
	{
		colours[d] = 0.1;
	}
	if((d + 1) % 3 == 2)
	{
		colours[d] = 0.1;
	}
	if((d + 1) % 3 == 0)
	{
		colours[d] = 0.1;
	}
	}
	else if(a == 1)
	{
	if((d + 1) % 3 == 1)
	{
		colours[d] = 0.15;
	}
	if((d + 1) % 3 == 2)
	{
		colours[d] = 0.15;
	}
	if((d + 1) % 3 == 0)
	{
		colours[d] = 0.15;
	}
	}
	else if(a == 2)
	{
	if((d + 1) % 3 == 1)
	{
		colours[d] = 0.2;
	}
	if((d + 1) % 3 == 2)
	{
		colours[d] = 0.2;
	}
	if((d + 1) % 3 == 0)
	{
		colours[d] = 0.2;
	}
	}
	if((d + 1) % 9 == 0)
	{
		a++;
	}
	d++;
}
d = 0;
 a = 1;
   while(d  < h)
{
    d++;
	if( a == 3)
	{
		a = 0;
		a++;	
	}
	else
	{
		a++;
	}
}



float cam_speed = 30.0f; // 1 unit per second
float cam_yaw_speed = 10.0f; // 10 degrees per second
float cam_pos[] = {0.0f, 0.0f, 2.0f}; // don't start at zero, or we will be too close
float cam_yaw = 0.0f; // y-rotation in degrees
/*float view_mat[] = { 
 1.0f, 0.0f, 0.0f, 0.0f,
 0.0f, 0.0f, 1.0f, -2.0f,
 0.0f, 0.0f, 0.0f, 1.0f
};*/
float view_mat[] = { 
 1.0f, 0.0f, -0.0f, 0.0f,
 0.0f, 1.0f, 0.0f, 0.0f,
 0.0f, 0.0f, 1.0f, 0.0f,
 0.0f, 0.0f, -2.0f, 1.0f
};
#define ONE_DEG_IN_RAD (2.0 * M_PI) / 360.0 // 0.017444444
// input variables
 float near = 0.1f; // clipping plane
 float far = 100.0f; // clipping plane
 float fov = 67.0f * ONE_DEG_IN_RAD; // convert 67 degrees to radians
 float aspect = (float)width / (float)height; // aspect ratio
 // matrix components
 float range = tan (fov * 0.5f) * near;
 float Sx = (2.0f * near) / (range * aspect + range * aspect);
 float Sy = near / range;
 float Sz = -(far + near) / (far - near);
 float Pz = -(2.0f * far * near) / (far - near);

float proj_mat[] = {
Sx, 0.0f, 0.0f, 0.0f,
0.0f, Sy, 0.0f, 0.0f,
0.0f, 0.0f, Sz, -1.0f,
0.0f, 0.0f, Pz, 0.0f
};



int	z;
z = 0;

while(z < 12)
{
	printf("%f", matrix[z]);
	z++;
}

int i;
puts("lamaison2");

int x, y, n;
int force_channels = 4;
/*unsigned char* image_data = stbi_load (argv[2], &x, &y, &n, force_channels);
if (!image_data) {
fprintf (stderr, "ERROR: could not loadidi %s\n", argv[2]);
}*/
unsigned char *image_data = NULL;
ft_putnbr(x);
ft_putnbr(y);
// NPOT check
if ((x & (x - 1)) != 0 || (y & (y - 1)) != 0) {
fprintf (
stderr, "WARNING: texture %s is not power-of-2 dimensions\n", argv[2]
);
}
/*printf ("first 4 bytes are: %i %i %i %i\n",
image_data[0], image_data[1], image_data[2], image_data[3]
);*/
puts("lamaison");
int width_in_bytes = x * 4;
unsigned char *top = NULL;
unsigned char *bottom = NULL;
unsigned char temp = 0;
int half_height = y / 2;

		for (int row = 0; row < half_height; row++) {
			top = image_data + row * width_in_bytes;
			bottom = image_data + (y - row - 1) * width_in_bytes;
			for (int col = 0; col < width_in_bytes; col++) {
				temp = *top;
				*top = *bottom;
				*bottom = temp;
				top++;
				bottom++;
			}
		}
	puts("lamaisoni3");



	puts("lamaisoni4");
	/* GL shader objects for vertex and fragment shader [components] */
	GLuint vs, fs;
	/* GL shader programme object [combined, to link] */
	GLuint shader_programme;
	GLuint uniformID;

	

	/* start GL context and O/S window using the GLFW helper library */
	if ( !glfwInit() ) {
		fprintf( stderr, "ERROR: could not start GLFW3\n" );
		return 1;
	}
	 glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	 glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
	 glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	 glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//	glfwWindowHint( GLFW_CONTEXT_VERSION_MAJOR, 2 );
	//	glfwWindowHint( GLFW_CONTEXT_VERSION_MINOR, 1 );
	window = glfwCreateWindow( 1640, 1480, "Hello Triangle", NULL, NULL );
	if ( !window ) {
		fprintf( stderr, "ERROR: could not open window with GLFW3\n" );
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent( window );
	// start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	/* get version info */
	renderer = glGetString( GL_RENDERER ); /* get renderer string */
	version = glGetString( GL_VERSION );	 /* version as a string */
	printf( "Renderer: %s\n", renderer );
	printf( "OpenGL version supported %s\n", version );

	// tell GL to only draw onto a pixel if the shape is closer to the viewer
	glEnable( GL_DEPTH_TEST ); // enable depth-testing
							// depth-testing interprets a smaller value as "closer"
	glDepthFunc( GL_LESS );

	/* a vertex buffer object (VBO) is created here. this stores an array of
		 data on the graphics adapter's memory. in our case - the vertex points */
	glGenBuffers( 1, &vbo );
	glBindBuffer( GL_ARRAY_BUFFER, vbo );
	glBufferData( GL_ARRAY_BUFFER,  sizeof( str65 ), str65, GL_STATIC_DRAW );

	GLuint colours_vbo = 0;
	glGenBuffers (1, &colours_vbo);
	glBindBuffer (GL_ARRAY_BUFFER, colours_vbo);
	glBufferData (GL_ARRAY_BUFFER, sizeof (colours), colours, GL_STATIC_DRAW);
	GLuint tex = 0;
	glGenTextures (1, &tex);
	glActiveTexture (GL_TEXTURE0);
	glBindTexture (GL_TEXTURE_2D, tex);
	glTexImage2D (GL_TEXTURE_2D, 0, GL_RGBA, x, y, 0, GL_RGBA, GL_UNSIGNED_BYTE, image_data);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri (GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf (GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


	/*GLfloat texcoords[] = {
	-6.0f, 6.0f,
	-6.0f, -6.0f,
	6.0, -6.0,
	6.0, -6.0,
	6.0, 6.0,
	-6.0, 6.0
	};*/
	GLuint vt_vbo;
	glGenBuffers (1, &vt_vbo);
	glBindBuffer (GL_ARRAY_BUFFER, vt_vbo);
	glBufferData (
	GL_ARRAY_BUFFER,
	sizeof (texcoords),
	texcoords,
	GL_STATIC_DRAW
	);

puts("lamaisoni5");
	/* the vertex array object (VAO) is a little descriptor that defines which
	data from vertex buffer objects should be used as input variables to vertex
	shaders. in our case - use our only VBO, and say 'every three floats is a
	variable' */
	glGenVertexArrays( 1, &vao );
	glBindVertexArray( vao );
	glEnableVertexAttribArray( 0 );
	glBindBuffer( GL_ARRAY_BUFFER, vbo );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, NULL );
	glBindBuffer (GL_ARRAY_BUFFER, colours_vbo);
	glVertexAttribPointer (1, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	glBindBuffer (GL_ARRAY_BUFFER, vt_vbo);
	// note: I assume that vertex positions are location 0
	//dimensions = 2; // 2d data for texture coords
	glVertexAttribPointer (2, 2, GL_FLOAT, GL_FALSE, 0, NULL);
	glEnableVertexAttribArray (2); // don't forget this!
	glEnableVertexAttribArray (0);
	glEnableVertexAttribArray (1);


	/* these are the strings of code for the shaders
	the vertex shader positions each vertex point */
	const char *vertex_shader = "#version 330\n"

"layout(location = 0) in vec3 vp;" 
"layout(location = 1) in vec3 vc;" 
"layout(location = 2) in vec2 vt;" // per-vertex texture co-ords
"out vec2 texture_coordinates;"
"uniform mat4 matrix;" // our matrix 
"uniform mat4 matrix8, view, proj;"
//"uniform mat4 matrix = mat4(1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.5, 0.0, 0.0, 1.0);"
//"uniform mat4 MVP;"
"out vec3 colour;"

"void main () {"
"texture_coordinates = vt;"
"colour = vc;"
"gl_Position = proj * view * matrix8 * vec4 (vp, 2.0);"
"}";

	/* the fragment shader colours each fragment (pixel-sized area of the
	triangle) */
	const char *fragment_shader = "#version 330\n"
	"in vec3 colour;"
	"out vec4 frag_colour;"
	"in vec2 texture_coordinates;"
	"uniform sampler2D basic_texture;"
	"uniform bool textura;"
	"void main () {"
"vec4 texel = texture (basic_texture, texture_coordinates);"
	"frag_colour =  vec4 (colour, 1.0);"
	"if(textura)"
	"{"
	"frag_colour = texel;"
	"}"
	"}";

/*	GLuint colorbuffer;
	glGenBuffers( 1, &colorbuffer );
	glBindBuffer( GL_ARRAY_BUFFER, colorbuffer );
	glBufferData( GL_ARRAY_BUFFER, 18 * sizeof( GLfloat ), g_color_buffer_data, GL_STATIC_DRAW );
	//	glBufferData( GL_ARRAY_BUFFER, sizeof( g_color_buffer_data ), g_color_buffer_data, GL_STATIC_DRAW );

	glEnableVertexAttribArray( 1 );
	glBindBuffer( GL_ARRAY_BUFFER, colorbuffer );
	glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 0, NULL );
	*/


	/* here we copy the shader strings into GL shaders, and compile them. we
		 then create an executable shader 'program' and attach both of the compiled
		 shaders. we link this, which matches the outputs of the vertex shader to
		 the inputs of the fragment shader, etc. and it is then ready to use */
//	mat4 MVP;
//	mat4_identity(MVP);

	vs = glCreateShader( GL_VERTEX_SHADER );
	glShaderSource( vs, 1, &vertex_shader, NULL );
	glCompileShader( vs );
	fs = glCreateShader( GL_FRAGMENT_SHADER );
	glShaderSource( fs, 1, &fragment_shader, NULL );
	glCompileShader( fs );
	shader_programme = glCreateProgram();
	glAttachShader( shader_programme, fs );
	glAttachShader( shader_programme, vs );
/*	glBindAttribLocation (shader_programme, 0, "vp");
	glBindAttribLocation (shader_programme, 1, "vc");*/
	glLinkProgram( shader_programme );
	glUseProgram (shader_programme);
	int matrix_location = glGetUniformLocation (shader_programme, "matrix8");
	glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix8);
	int view_mat_location = glGetUniformLocation (shader_programme, "view");
	glUseProgram (shader_programme);
	glUniformMatrix4fv (view_mat_location, 1, GL_FALSE, view_mat);
	int proj_mat_location = glGetUniformLocation (shader_programme, "proj");
	glUseProgram (shader_programme);
	glUniformMatrix4fv (proj_mat_location, 1, GL_FALSE, proj_mat);
	int tex_loc = glGetUniformLocation (shader_programme, "basic_texture");
	glUseProgram (shader_programme);
	glUniform1i (tex_loc, 0); // use active texture 0


//	puts(image_data[65]);

	/* this loop clears the drawing surface, then draws the geometry described
		 by the VAO onto the drawing surface. we 'poll events' to see if the window
		 was closed, etc. finally, we 'swap the buffers' which displays our drawing
		 surface onto the view area. we use a double-buffering system which means
		 that we have a 'currently displayed' surface, and 'currently being drawn'
		 surface. hence the 'swap' idea. in a single-buffering system we would see
		 stuff being drawn
	one-after-the-other */
	float teta = 0;
	float speed = 1.0f; // move at 1 unit per second
	float last_position = 0.0f;
	float last1_position = 0.0f;
	float last2_position = 0.0f;
//	float last3_position = 0.0f
	while ( !glfwWindowShouldClose( window ) ) {

			// add a timer for doing animation
			double previous_seconds = glfwGetTime();
			double current_seconds = glfwGetTime();
			double elapsed_seconds = current_seconds - previous_seconds;
			double elapsed1_seconds = current_seconds - previous_seconds;
			double elapsed2_seconds = current_seconds - previous_seconds;
			double elapsed3_seconds = current_seconds - previous_seconds;
			previous_seconds = current_seconds;

			// reverse direction when going to far left or right
				if (fabs(last_position) > 1.0f) {
					speed = -speed;
				}

//float	*produit_matricielle4(float mat1[], float mat2[], float teta)
		if (glfwGetKey (window, GLFW_KEY_EQUAL)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position; 
			last2_position = matrix7[14];
			teta = teta + 0.01;
			
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	

			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_RIGHT)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position + 0.01f; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position; 
			last2_position = matrix7[14];

			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	

			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
/*		if (glfwGetKey (window, GLFW_KEY_RIGHT)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix[12] = elapsed_seconds * speed + last_position + 0.01f; 
			last_position = matrix[12]; 
			matrix[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix[13]; 
			matrix[14] = elapsed2_seconds * speed + last2_position; 
			last2_position = matrix[14]; 
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix);
		}*/
		if (glfwGetKey (window, GLFW_KEY_LEFT)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position - 0.01f; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position; 
			last2_position = matrix7[14]; 
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_UP)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position + 0.01f; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position; 
			last2_position = matrix7[14]; 
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_DOWN)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position - 0.01f; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position ;
			last2_position = matrix7[14];
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_SPACE)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position + 0.01f; 
			last2_position = matrix7[14]; 
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_M)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position - 0.01f; 
			last2_position = matrix7[14]; 
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_M)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
			matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position - 0.01f; 
			last2_position = matrix7[14]; 
			matrix8 = matrix_y(teta, l);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);
		}
		if (glfwGetKey (window, GLFW_KEY_N)) {
//			glfwSetWindowShouldClose (window, 1);
			// update the matrix 
	/*		matrix7[12] = elapsed_seconds * speed + last_position; 
			last_position = matrix7[12]; 
			matrix7[13] = elapsed1_seconds * speed + last1_position; 
			last1_position = matrix7[13]; 
			matrix7[14] = elapsed2_seconds * speed + last2_position; 
			last2_position = matrix7[14]; 
			matrix8 = matrix_y(teta, 0.0);
		   	matrix3 = produit_matricielle4(matrix7, matrix8, 56);	
			glUseProgram (shader_programme); 
			glUniformMatrix4fv (matrix_location, 1, GL_FALSE, matrix3);*/
			textura = 1;
			uniformID  = glGetUniformLocation(shader_programme, "textura");
			glUseProgram(shader_programme);
			glUniform1f(uniformID, textura);
		}
 
		// wipe the drawing surface clear
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glUseProgram( shader_programme );
		glBindVertexArray( vao );
		// draw points 0-3 from the currently bound VAO with current shader
		glDrawArrays( GL_TRIANGLES, 0, 3 * nb_tr);
		// update other events like input handling
		glfwPollEvents();
		// put the stuff we've been drawing onto the display
		glfwSwapBuffers( window );
	}

	// close GL context and any other GLFW resources
	glfwTerminate();
	return 0;
}
