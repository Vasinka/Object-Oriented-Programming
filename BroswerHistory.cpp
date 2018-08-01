#include "stdafx.h"
#include "iostream"
using namespace std;

struct HistoryEntry
{

                int month;

                char* value;

};



class BrowserHistory
{

public:

                BrowserHistory(int limit)

 {

                                count = 0;

                                for (int i = 0; i < 12; i++)

                                {

                                                entriesByMonth[i] = 0;

                                }

                                maxCount = limit;

                }



                void AddEntry(HistoryEntry entry)

                {

                                if (count >= maxCount)

                                {

                                                return;

                                }

                                entries[count] = entry;

                                entriesByMonth[entry.month - 1]++;

                                count++;



                }



                int GetMonthWithMostMovies()

                {

                                int max = 0;

                                for (int i = 0; i < 12; i++)

                                {

                                                if (entriesByMonth[i] > entriesByMonth[max])

                                                {

                                                                max = i;

                                                }

                                }



                                return max + 1;



                }



                void PrintHistory()

                {

                                for (int i = 0; i < count; i++)

                                {

                                                cout << "Month: " << (entries[i].month + 1) << "; Site:" << (entries[i].value) << endl;

                                }

                }



                int SitesPerMonth(int i)

                {

                                return entriesByMonth[i - 1];

                }



                void RemoveLatestEntry()

                {

                                if (count <= 0)

                                {

                                                return;

                                }

                                entriesByMonth[entries[count - 1].month - 1] --;

                                count--;

                }



                HistoryEntry ConcatenateEntries(HistoryEntry entry1, HistoryEntry entry2)

                {

                                int newSize = strlen(entry1.value) + strlen(entry2.value) + 1;



                                char *newValue = (char *)malloc(newSize);

                                strcpy_s(newValue, newSize, entry1.value);

                                strcat_s(newValue, newSize, entry2.value);



                                HistoryEntry newEntry = {};

                                newEntry.month = entry1.month;

                                newEntry.value = newValue;



                                return newEntry;

                }



                int Count()
                {

                    return count;

                }



private:

                HistoryEntry entries[1000];

                int entriesByMonth[12];

                int count;

                int maxCount;

};



bool testBrowserHistory()

{

                bool pass = true;

                int limit = 5;

                // test history initialization

                BrowserHistory history = BrowserHistory(limit);


                // test history  entry initialization

                char foo[4] = "foo";

                char bar[4] = "bar";

                HistoryEntry entry1 = {};

                HistoryEntry entry2 = {};

                entry1.month = 1;

                entry1.value = foo;

                entry2.month = 2;

                entry2.value = bar;



                // test adding new history items

                history.AddEntry(entry2);

                history.AddEntry(entry1);

                pass = history.Count() == 2 && pass;



                // test removing history items

                history.RemoveLatestEntry();

                pass = history.Count() == 1 && pass;



                // test concat

                HistoryEntry entry3 = history.ConcatenateEntries(entry1, entry2);

                history.AddEntry(entry3);

                pass = history.Count() == 2 && pass;



                // test history limit

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                history.AddEntry(entry3);

                pass = history.Count() == limit && pass;



                // test fetching month with most movies

                pass = history.GetMonthWithMostMovies() == 1 && pass;



                // test sites per month

                pass = history.SitesPerMonth(1) == 4 && pass;



                return pass;

}



int main() {

                cout << testBrowserHistory();
                return 0;

}
