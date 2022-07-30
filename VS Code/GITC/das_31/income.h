#include <iostream>
class Income
{
    public:
        std::string name;
        double fromStore;
        double fromTender;
        double fromInstalation;
        double fromCashBack;
        double fromService;

        double total;

    
        Income(){}
        Income(std::string na, double st, double te, double in, double ca, double se)
        {
            name = na;
            fromStore = st;
            fromTender = te;
            fromInstalation = in;
            fromCashBack = ca;
            fromService = se;

            total = st + te + in + ca + se; 
        }

        friend std::ostream& operator<<(std::ostream& tpel, const Income obj)
        {
            std::cout << "==============" << std::endl;
            tpel << "Name:\t" << obj.name << std::endl;
            tpel << "From Store:\t" << obj.fromStore << std::endl;
            tpel << "From Tender:\t" << obj.fromTender << std::endl;
            tpel << "From Instalation:\t" << obj.fromInstalation << std::endl;
            tpel << "From Cash Back:\t" << obj.fromCashBack << std::endl;
            tpel << "From Service:\t" << obj.fromService << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~" << std::endl;
            tpel << "AVERAGE:\t" << obj.total << std::endl;
            return tpel;
        }
};