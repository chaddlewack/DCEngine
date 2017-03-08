#pragma once

#include "layer.h"
#include "../batchRenderer2D.h"

namespace DCEngine {namespace graphics {

		class TileLayer : public Layer {
		public:
			TileLayer(Shader* shader);
			~TileLayer();
		};

}}