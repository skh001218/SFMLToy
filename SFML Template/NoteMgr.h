#pragma once


class NoteMgr : public Singleton<NoteMgr>
{
	friend Singleton<NoteMgr>;
protected:
	std::list<Note> notes;

public:
	NoteMgr() = default;
	~NoteMgr() = default;
	NoteMgr(const NoteMgr& other) = delete;
	NoteMgr& operator=(const NoteMgr& other) = delete;

	void Init();
	void SetNotes();

};

