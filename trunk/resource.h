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
	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\7z.sfx"
	public: static const RCDATA _7Z_SFX;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\7zS.sfx"
	public: static const RCDATA _7ZS_SFX;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\execute_file.png"
	public: static const RCDATA EXECUTE_FILE_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\execute_file_disabled.png"
	public: static const RCDATA EXECUTE_FILE_DISABLED_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\folder_open.png"
	public: static const RCDATA FOLDER_OPEN_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\folder_open_disabled.png"
	public: static const RCDATA FOLDER_OPEN_DISABLED_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\report.png"
	public: static const RCDATA REPORT_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\report_disabled.png"
	public: static const RCDATA REPORT_DISABLED_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\title.png"
	public: static const RCDATA TITLE_PNG;

	// File: "D:\- MY DATA -\Software-Projects\7z SFX Creator\trunk\res\title_disabled.png"
	public: static const RCDATA TITLE_DISABLED_PNG;
};

#endif // RESOURCES_H
