#include "Expression.h"

class Var: public Expression
{


    public:
        virtual double value() const override;
        virtual void print() const override;

        void setValue(double newVariable);
        void setName(const char *);

        Var();
        ~Var();
        Var(const char * n_name, double n_val);
        Var(const Var&);
        Var& operator=(const Var&);

        void helperPrint() const override;
        Expression * clone() const override;

    private:
        char* name;
        double val;
};
