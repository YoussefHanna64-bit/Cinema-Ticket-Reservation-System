#include"MasterCard.hpp"

MasterCard::MasterCard(std::string cardNumber, int cvv)
    :cardNumber(cardNumber), cvv(cvv) {}

void MasterCard::makePayment()
{
    std::cout << "Payment by master card is done successfully" << std::endl;
}