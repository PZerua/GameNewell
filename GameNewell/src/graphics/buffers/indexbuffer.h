/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under GPL v2 license. Read LICENSE for more details.
*/

#pragma once

#include <GL/glew.h>

namespace gfx
{

	class IndexBuffer
	{
	private:
		GLuint m_eboId;
		GLsizei m_size;
		
	public:

		IndexBuffer(GLushort *data, GLuint size);
		~IndexBuffer();

		void bind() const;
		void unbind() const;
	};

} // namespace gfx