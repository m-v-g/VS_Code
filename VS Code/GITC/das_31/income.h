using namespace std;
class Income
{
    public:
        double fromStore;
        double fromTender;
        double fromInstalation;
        double fromCashBack;
        double fromService;

        double total;

    
        Income(){}
        Income(double st, double te, double in, double ca, double se)
        {
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
            tpel << "Rect a:\t" << rec.a << endl;
            tpel << "Rect b:\t" << rec.b << endl;
            tpel << "Rect area:\t" << rec.area << endl;
            tpel << "Rect perimetr:\t" << rec.perimetr << endl;
            return tpel;
        }
};