#include "YCircleCollider2D.h"
#include "YTransform.h"
#include "YGameObject.h"

namespace yam
{
    CircleCollider2D::CircleCollider2D()
        : Collider(enums::eColliderType::Circle2D)
    {
    }
    CircleCollider2D::~CircleCollider2D()
    {
    }
    void CircleCollider2D::Initialize()
    {
    }
    void CircleCollider2D::Update()
    {
    }
    void CircleCollider2D::LateUpdate()
    {
    }
    void CircleCollider2D::Render(HDC hdc)
    {
        Transform* tr = GetOwner()->GetComponent<Transform>();
        Vector2 pos = tr->GetPosition();

        Vector2 offset = GetOffset();

        HBRUSH transparentBrush = (HBRUSH)GetStockObject(NULL_BRUSH);
        HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, transparentBrush);

        HPEN greenPen = (HPEN)CreatePen(PS_SOLID, 2, RGB(0, 255, 0));
        HPEN oldPen = (HPEN)SelectObject(hdc, greenPen);

        Ellipse(hdc, pos.x + offset.x
            , pos.y + offset.y
            , pos.x + offset.x + 100 * GetSize().x
            , pos.y + offset.y + 100 * GetSize().y);

        SelectObject(hdc, oldBrush);
        SelectObject(hdc, oldPen);

        DeleteObject(greenPen);
    }
}