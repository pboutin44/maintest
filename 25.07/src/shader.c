/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pboutin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 18:51:04 by pboutin           #+#    #+#             */
/*   Updated: 2017/07/25 15:20:29 by pboutin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scope.h"

char	*vertex(void)
{
	char	*str;

	str = "#version 330\n"
		"layout(location = 0) in vec3 vp;"
		"layout(location = 1) in vec3 vc;"
		"layout(location = 2) in vec2 vt;"
		"out vec2 texture_coordinates;"
		"uniform mat4 matrix;"
		"uniform mat4 matrix8, view, proj;"
		"out vec3 colour;"
		"void main () {"
		"texture_coordinates = vt;"
		"colour = vc;"
		"gl_Position = proj * view * matrix8 * vec4 (vp, 2.0);}";
	return (str);
}

char	*fragment(void)
{
	char	*str;

	str = "#version 330\n"
		"in vec3 colour;"
		"out vec4 frag_colour;"
		"in vec2 texture_coordinates;"
		"uniform sampler2D basic_texture;"
		"uniform bool textura;"
		"void main () {"
		"vec4 texel = texture (basic_texture, texture_coordinates);"
		"frag_colour =  vec4 (colour, 1.0);"
		"if(textura){frag_colour = texel;}}";
	return (str);
}
