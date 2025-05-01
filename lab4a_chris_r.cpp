// Name: Chris Rumble
// Date: February 24, 2025
// Description: This program will print a sales receipt of a valentine order. The user will input the number of milk chocolates, white chocolates, and roses they would like to purchase. The program will calculate the subtotal for each category, the discount amount, sales tax, and grand total. The program will then output a receipt with the number of each item, the price per item, the total price for each category, the discount amount, sales tax, and grand total.
#include <iostream> // Needed for cin and cout.
#include <iomanip>  // Needed for setprecision.
using namespace std;

//  Prices for milk chocolate, white chocolate, and rose
const double PRICE_MILK = 10.50;
const double PRICE_WHITE = 12.50;
const double PRICE_ROSE = 15.50;
const double SALES_TAX_RATE = 0.10;

int main()
{
    // double purchaseAmount, discount, discountedAmount;
    double NumMilk = 0, NumWhite = 0, NumRose = 0;             // Order quantity
    double TotalMilk = 0.0, TotalWhite = 0.0, TotalRose = 0.0; // Subtotal for each categories
    double Discount = 0.0, DiscountAmount = 0.0;
    double SalesTax = 0.0, Subtotal = 0.0, GrandTotal = 0.0;

    cout << "Number of milk chocolate at 10.50 each: ";
    cin >> NumMilk;
    cout << "Number of white chocolate at 12.50 each: ";
    cin >> NumWhite;
    cout << "Number of roses at 15.50 each: ";
    cin >> NumRose;
    // Calculation of subtotal price of each category
    TotalMilk = NumMilk * PRICE_MILK;
    TotalWhite = NumWhite * PRICE_WHITE;
    TotalRose = NumRose * PRICE_ROSE;
    Subtotal = TotalMilk + TotalWhite + TotalRose;
    // Determine the discount based on the purchase amount
    if (Subtotal < 0)
        cout << "Invalid input" << endl;
    else if (Subtotal < 20.00)
        Discount = 0.0;
    else if (Subtotal >= 20.00 && Subtotal <= 39.99)
        Discount = 0.10;
    else if (Subtotal >= 40.00 && Subtotal <= 59.99)
        Discount = 0.15;
    else if (Subtotal >= 60.00 && Subtotal <= 79.99)
        Discount = 0.20;
    else if (Subtotal > 79.99)
        Discount = 0.25;

    // Calculate the discounted amount, sales tax, and grand total.
    DiscountAmount = Discount * Subtotal;
    SalesTax = Subtotal * SALES_TAX_RATE;
    GrandTotal = Subtotal + SalesTax;

    // Complete all of the output statements to format a receipt.
    // Output the receipt header.
    cout << endl
         << endl
         << "Happy Valentine Receipt" << endl;
    cout << "-----------------------" << endl
         << endl;
    // Set the decimal precision to 2.
    cout << fixed << setprecision(2);
    // Output the number of milk chocolates, price per chocolate, and total price.
    cout << NumMilk << left << setw(20) << " Milk Chocolate(s)" << " (" << PRICE_MILK << " each)" << right << setw(10) << TotalMilk << endl;
    // Output the number of white chocolates, price per chocolate, and total price.
    cout << NumWhite << left << setw(20) << " White Chocolate(s)" << " (" << PRICE_WHITE << " each)" << right << setw(10) << TotalWhite << endl;
    // Output the number of roses, price per rose, and total price.
    cout << NumRose << left << setw(20) << " Roses(s)" << " (" << PRICE_ROSE << " each)" << right << setw(10) << TotalRose << endl;
    cout << endl;
    // Output the discount amount.
    cout << left << setw(30) << "Discount Amount" << right << setw(17) << DiscountAmount << endl;
    // Output the sales tax.
    cout << left << setw(30) << "Sales Tax" << right << setw(17) << SalesTax << endl;
    cout << endl;
    // Output the grand total.
    cout << left << setw(30) << "Grand Total" << right << setw(17) << GrandTotal << endl;
    cout << endl;
    cout << endl;

    return 0;
}