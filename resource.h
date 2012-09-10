/************************************************************************
*             INCLUDE THIS HEADER FILE INTO YOUR PROJECT                *
*************************************************************************
* Accessing binary data of a member:           RESOURCES::MEMBER.data   *
* Getting the binary data size of a member:    RESOURCES::MEMBER.length *
************************************************************************/

#ifndef RESOURCES_H
#define RESOURCES_H

struct RCDATA
{
	unsigned int length;
	unsigned char* data;
};

struct RESOURCES
{
	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\7z.sfx.zip"
	public: static const RCDATA _7Z_SFX_ZIP;
	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\7zS.sfx.zip"
	public: static const RCDATA _7ZS_SFX_ZIP;
};

#endif // RESOURCES_H
