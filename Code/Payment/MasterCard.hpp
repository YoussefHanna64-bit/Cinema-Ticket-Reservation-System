#include "Payment.hpp"

class MasterCard : public Payment
{

private:
    std::string cardNumber;
    int cvv;

public:
    MasterCard(std::string cardNumber, int cvv);
    void makePayment()override;

};