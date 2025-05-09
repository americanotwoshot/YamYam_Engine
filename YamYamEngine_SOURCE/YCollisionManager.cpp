#include "YCollisionManager.h"
#include "YScene.h"
#include "YSceneManager.h"
#include "YGameObject.h"
#include "YCollider.h"
#include "YTransform.h"

namespace yam
{
	std::bitset<(UINT)eLayerType::Max> CollisionManager::mCollisionLayerMatrix[(UINT)eLayerType::Max]{};
	std::unordered_map<UINT64, bool> CollisionManager::mCollisionMap = {};

	void CollisionManager::Initialize()
	{
	}
	void CollisionManager::Update()
	{
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision((eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render()
	{
	}

	void CollisionManager::Clear()
	{
		mCollisionMap.clear();
		mCollisionLayerMatrix->reset();
	}

	void CollisionManager::CollisionLayerCheck(eLayerType left, eLayerType right, bool enable)
	{
		int row = 0;
		int col = 0;

		if (left <= right) 
		{
			row = (UINT)left;
			col = (UINT)right;
		}
		else
		{
			row = (UINT)right;
			col = (UINT)left;
		}

		mCollisionLayerMatrix[row][col] = enable;
	}
	void CollisionManager::LayerCollision(eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& leftObjs = SceneManager::GetGameObjects(left);
		const std::vector<GameObject*>& rightObjs = SceneManager::GetGameObjects(right);

		for (GameObject* leftObj : leftObjs)
		{
			if (leftObj->IsActive() == false)
				continue;
			Collider* leftCol = leftObj->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* rightObj : rightObjs)
			{
				if (rightObj->IsActive() == false)
					continue;
				Collider* rightCol = rightObj->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (leftObj == rightObj)
					continue;

				ColliderCollision(leftCol, rightCol);
			}
		}

	}
	void CollisionManager::ColliderCollision(Collider* left, Collider* right)
	{
		CollisionID id = {};
		id.left = left->GetID();
		id.right = right->GetID();

		auto iter = mCollisionMap.find(id.id);
		if (iter == mCollisionMap.end())
		{
			mCollisionMap.insert(std::make_pair(id.id, false));
			iter = mCollisionMap.find(id.id);
		}

		// 충돌 체크
		if (Intersect(left, right))
		{
			// 최초 충돌일 때
			if (iter->second == false) 
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // 이미 충돌 중
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{	// 충돌 벗어날 때
			if (iter->second == true)
			{
				left->OnCollisionExit(right);
				right->OnCollisionExit(left);
				iter->second = false;
			}
		}
	}
	bool CollisionManager::Intersect(Collider* left, Collider* right)
	{
		Transform* leftTr = left->GetOwner()->GetComponent<Transform>();
		Transform* rightTr = right->GetOwner()->GetComponent<Transform>();

		Vector2 leftPos = leftTr->GetPosition() + left->GetOffset();
		Vector2 rightPos = rightTr->GetPosition() + right->GetOffset();

		// size 1, 1 일 때, 기본크기가 100 픽셀
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// AABB 충돌
		enums::eColliderType leftType = left->GetColliderType();
		enums::eColliderType rightType = right->GetColliderType();

		// RECT - RECT
		if (leftType == enums::eColliderType::Rect2D
			&& rightType == enums::eColliderType::Rect2D)
		{
			if (fabs(leftPos.x - rightPos.x) < fabs(leftSize.x / 2.0f + rightSize.x / 2.0f)
				&& fabs(leftPos.y - rightPos.y) < fabs(leftSize.y / 2.0f + rightSize.y / 2.0f))
				return true;
		}

		// CIRCLE - CIRCLE
		if (leftType == enums::eColliderType::Circle2D
			&& rightType == enums::eColliderType::Circle2D)
		{
			Vector2 leftCirclePos = leftPos + (leftSize / 2.0f);
			Vector2 rightCirclePos = rightPos + (rightSize / 2.0f);

			float distance = (leftCirclePos - rightCirclePos).Length();
			if (distance <= (leftSize.x / 2.0f + rightSize.x / 2.0f))
			{
				return true;
			}
		}

		// CIRCLE - RECT
		if ((leftType == enums::eColliderType::Rect2D && rightType == enums::eColliderType::Circle2D))
		{
			Vector2 boxSize;
			boxSize.x = leftSize.x + rightSize.x;
			boxSize.y = leftSize.y + rightSize.y;

			if (rightPos.x < leftPos.x + (boxSize.x / 2.0f) 
				&& rightPos.x > leftPos.x - (boxSize.x / 2.0f)
				&& rightPos.y < leftPos.y + (boxSize.y / 2.0f) 
				&& rightPos.y > leftPos.y - (boxSize.y / 2.0f))
				return true;
		}
		if ((leftType == enums::eColliderType::Circle2D && rightType == enums::eColliderType::Rect2D))
		{
			Vector2 boxSize;
			boxSize.x = leftSize.x + rightSize.x;
			boxSize.y = leftSize.y + rightSize.y;

			if (leftPos.x < rightPos.x + (boxSize.x / 2.0f)
				&& leftPos.x > rightPos.x - (boxSize.x / 2.0f)
				&& leftPos.y < rightPos.y + (boxSize.y / 2.0f)
				&& leftPos.y > rightPos.y - (boxSize.y / 2.0f))
				return true;
		}

		return false;
	}
}