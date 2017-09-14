/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under GPL v2 license. Read LICENSE for more details.
*/

#pragma once

#include <vector>
#include <memory>

#include <src/math/math.h>
#include "src/graphics/buffers/vertexarray.h"
#include "src/graphics/buffers/vertexbuffer.h"
#include "src/graphics/buffers/indexbuffer.h"

#define QUAD_INDICES_SIZE 6
#define QUAD_VERTEX_SIZE 12
#define QUAD_VERTEXCOLOR_SIZE 24

namespace gfx
{

	class Renderable2D
	{
	private:
		math::vec2 m_size;
		math::vec4 m_color;
		std::vector<float> m_vertexData;
		std::unique_ptr<VertexBuffer> m_vbo;

	public:
		Renderable2D(math::vec2 position, math::vec2 size, math::vec4 color);
		Renderable2D(math::vec2 position, math::vec2 size);
		std::unique_ptr<VertexArray> m_vao;
		static std::unique_ptr<IndexBuffer> m_ebo;
		math::mat4 m_modelMatrix;

	private:
		void initVao(unsigned char flag = 0);
		void initVbo(unsigned char flag = 0);
		void initEbo();
	};

} // namespace gfx