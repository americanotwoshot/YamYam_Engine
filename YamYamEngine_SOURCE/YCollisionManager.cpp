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
		Scene* scene = SceneManager::GetActiveScene();
		for (UINT row = 0; row < (UINT)eLayerType::Max; row++)
		{
			for (UINT col = 0; col < (UINT)eLayerType::Max; col++)
			{
				if (mCollisionLayerMatrix[row][col] == true)
				{
					LayerCollision(scene, (eLayerType)row, (eLayerType)col);
				}
			}
		}
	}
	void CollisionManager::LateUpdate()
	{
	}
	void CollisionManager::Render(HDC hdc)
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
	void CollisionManager::LayerCollision(Scene* scene, eLayerType left, eLayerType right)
	{
		const std::vector<GameObject*>& lefts = SceneManager::GetGameObjects(left);
		const std::vector<GameObject*>& rights = SceneManager::GetGameObjects(right);

		for (GameObject* left : lefts)
		{
			if (left->IsActive() == false)
				continue;
			Collider* leftCol = left->GetComponent<Collider>();
			if (leftCol == nullptr)
				continue;

			for (GameObject* right : rights)
			{
				if (right->IsActive() == false)
					continue;
				Collider* rightCol = right->GetComponent<Collider>();
				if (rightCol == nullptr)
					continue;
				if (left == right)
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

		// �浹 üũ
		if (Intersect(left, right))
		{
			// ���� �浹�� ��
			if (iter->second == false) 
			{
				left->OnCollisionEnter(right);
				right->OnCollisionEnter(left);
				iter->second = true;
			}
			else // �̹� �浹 ��
			{
				left->OnCollisionStay(right);
				right->OnCollisionStay(left);
			}
		}
		else
		{	// �浹 ��� ��
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

		// size 1, 1 �� ��, �⺻ũ�Ⱑ 100 �ȼ�
		Vector2 leftSize = left->GetSize() * 100.0f;
		Vector2 rightSize = right->GetSize() * 100.0f;

		// AABB �浹
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

			float distance = (leftCirclePos - rightCirclePos).length();
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