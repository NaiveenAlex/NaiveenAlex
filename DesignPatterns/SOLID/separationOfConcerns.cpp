struct Journal
{
    string title;
    vector<string> entries;
    
    Journal(const string& title) : title(title) {}

    void add_entry(const string& entry)
    {
        static int count = 1;
        entries.push_back(lexical_cast<string>(count++) + ":" + entry);
    }
};

//Separation of concerns, move the persistence part to a separate class.
struct PersistenceManager()
{
    static void save(const Journal& j, const string& filename)
    {
        ofstream ofs(filename);
        for (auto &e : j.entries)
		ofs << e << endl;
    }
}


int main()
{
	Journal journal("Dear Diary");
	journal.add_entry("I ate a bug.");
	journal.add_entry("I cried today.");

	PersistenceManager pm;
	pm.save(journal, "save.txt");

}
