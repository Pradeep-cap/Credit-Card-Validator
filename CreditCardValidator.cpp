#include <bits/stdc++.h>
using namespace std;

// Function to get digit sum after doubling
int digit(int n) {
    return n % 10 + (n / 10 % 10);
}

// Get even place sum (starting from second-to-last digit)
int getEvenSum(string card) {
    int sum = 0;
    for (int i = card.size() - 2; i >= 0; i -= 2) {
        sum += digit((card[i] - '0') * 2);
    }
    return sum;
}

// Get odd place sum
int getOddSum(string card) {
    int sum = 0;
    for (int i = card.size() - 1; i >= 0; i -= 2) {
        sum += (card[i] - '0');
    }
    return sum;
}

// Detect card type
string getCardType(string card) {
    if (card[0] == '4')
        return "Visa";
    else if (card[0] == '5')
        return "MasterCard";
    else if (card.substr(0, 2) == "34" || card.substr(0, 2) == "37")
        return "American Express";
    else if (card.substr(0, 4) == "6011")
        return "Discover";
    else
        return "Unknown";
}

int main() {
    string card;
    cout << "*******************************\n";
    cout << "Enter the credit card number without spaces: ";
    cin >> card;

    int total = getOddSum(card) + getEvenSum(card);

    if (total % 10 == 0) {
        cout << card << " --> This card is VALID ✅\n";
        cout << "Card Type: " << getCardType(card) << endl;
    } else {
        cout << card << " --> This card is NOT valid ❌\n";
    }
    cout << "*******************************\n";
}
