#include <iostream>
#include <regex>
using namespace std;



int main()
{
    regex hamaranisher("([0-9]{2}[A-Z]{2}[0-9]{3})|([0-9]{3}[A-Z]{2}[0-9]{2})"); //haykakan hamaranisheri shablon
    regex sayter("[A-Za-z_\\-]{2,50}\\.am"); //haykakan sayter
    regex heraxos("(\\+374|0)[0-9]{2} [0-9]{2}(-| )?[0-9]{2}(-| )?[0-9]{2}");
    regex anun("[A-Z]{1}[a-z]{3,} [A-Z]{1}[a-z]{3,}(ian|yan|iants|yants|uni)");
    //regex date("[0-31]{1}(\\.|\\-|/| ){1}[0-12]{1}(\\.|\\-|/){1}[0-9]{4} [0-24]{1}:[0-59]{1}(:[0-59]{1})");
    //regex date("[0-3]{1}[0-9]{1}(\\.|\\-|/| )[0-1]{1}[0-9]{1}(\\.|\\-|/| )[0-9]{4} [0-2]{1}[0-9]{1}:[0-5]{1}[0-9]{1}(:[0-5]{1}[0-9]{1})?");
    regex date ("((0[0-9])|(1[0-9])|(2[0-9])|(3[01]))(\\.|\\-|/| )"
                "((0[0-9])|(1[012]))(\\.|\\-|/| )"
                "((19[7-9][0-9])|(20[0-9][0-9])) "
                "((0[0-9])|(1[0-9])|(2[0-4])):"
                "([0-5]{1}[0-9]{1})"
                "(:([0-5]{1}[0-9]{1}))?");
    regex pasport("[A-Z]{2}[0-9]{7}");
   

    string text = "gfgfh 45AV111 jhjh 222AV45"
    "news.am 467646457oiyiuuih News.am"
    "+37477 05-70-66 HFHGFHFHFHJJJGJGJ 096 63 62 01 JGGGHGFHFJGJ 096 63-62-01 JJJKJKHJKHKJH +37477 057066"
    "Vasil Mkrtchyan    VAsil Mkrtchyan   vasil Mkrtchyan   Vasil mkrtchyan"
    "02.07.2022 14:17     02/07/2022 14:17     02-07-2022 14:17:59   02 07 2022 14:45:59    32.17.2022 25:58";


    smatch vxojdenie; //klas vor@ kpahi sparich informacia
    
    

    while(regex_search(text, vxojdenie, hamaranisher))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }

    while(regex_search(text, vxojdenie, sayter))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }

    while(regex_search(text, vxojdenie, heraxos))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }

    while(regex_search(text, vxojdenie, anun))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }

    while(regex_search(text, vxojdenie, date))
    {
        cout << vxojdenie[0] << endl;
        text = vxojdenie.suffix().str();
    }


    return 0;
}

