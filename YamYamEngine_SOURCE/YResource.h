#pragma once
#include "YEntity.h"

namespace yam
{
	class Resource : public Entity	// 추상 클래스
	{
	public:
		Resource(enums::eResourceType mType);
		virtual ~Resource();

		virtual HRESULT Save(const std::wstring& path) = 0;
		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
}

