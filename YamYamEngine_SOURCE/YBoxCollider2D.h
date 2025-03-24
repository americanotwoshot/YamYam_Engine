#pragma once
#include "YCollider.h"

namespace yam
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render() override;

	private:
	};
}

