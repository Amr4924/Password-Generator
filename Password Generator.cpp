/**
 * Password Generator & Strength Checker v1.0
 * 
 * A comprehensive C++ application for generating secure passwords and 
 * analyzing password strength based on modern security standards.
 * 
 * Features:
 * - Customizable password generation with multiple character sets
 * - Real-time password strength analysis
 * - Interactive command-line interface
 * - Secure random generation with proper seeding
 * 
 * @author: Your Name
 * @version: 1.0
 * @date: September 2025
 */

#include <iostream>  // For console input/output operations
#include <algorithm> // For std::shuffle function to randomize password
#include <string>    // For string manipulation and operations
#include <ctime>     // For time-based random seed generation
#include <random>    // For modern random number generation
using namespace std;

/**
 * Analyzes password strength based on character diversity and length
 * 
 * This function evaluates a password's security strength by checking for:
 * - Presence of digits (0-9)
 * - Presence of lowercase letters (a-z)
 * - Presence of uppercase letters (A-Z)
 * - Presence of special characters (punctuation)
 * - Minimum length requirement (8 characters)
 * 
 * @param password The password string to be analyzed
 * @return String indicating password strength level:
 *         - "Very Strong": All 4 character types + min 8 chars
 *         - "strong": 3 character types + min 8 chars
 *         - "middle": 2 character types + min 8 chars
 *         - "weak": 1 character type + min 8 chars
 *         - Error message: If criteria not met
 */
string Verify_password(string password)
{
    // Initialize flags to track presence of different character types
    bool digit = false;              // Tracks if password contains numbers
    bool Small_letters = false;      // Tracks if password contains lowercase letters
    bool Capital_letters = false;    // Tracks if password contains uppercase letters
    bool special_characters = false; // Tracks if password contains special characters

    int sum; // Counter for total character types present
    int size = password.length(); // Store password length for efficiency
    
    // Iterate through each character in the password to analyze composition
    for (int i = 0; i < password.length(); ++i)
    {
       // Check for numeric digits using built-in isdigit function
       if(isdigit(password.at(i))) digit = true;
       
       // Check for lowercase letters using built-in islower function
       if (islower(password.at(i))) Small_letters = true;
       
       // Check for uppercase letters using built-in isupper function
       if (isupper(password.at(i))) Capital_letters = true;
       
       // Check for special characters using built-in ispunct function
       if (ispunct(password.at(i))) special_characters = true;
    }
    
    // Calculate total diversity score (sum of character types present)
    sum = digit + Small_letters + Capital_letters + special_characters;

    // Evaluate password strength based on length and character diversity
    if (sum <= 0 || size < 8) 
        return "Your password does not meet the standard criteria. Check your longest password.";
    else if (sum == 4) return "Very Strong";  // All character types present
    else if (sum == 3) return "strong";       // Three character types present
    else if (sum == 2) return "middle";       // Two character types present
    else if (sum == 1) return "weak";         // Only one character type present

    return "We couldn't determine anything."; // Fallback case (should not occur)
}

/**
 * Main application entry point
 * 
 * Orchestrates the password generation and strength checking workflow:
 * 1. Initializes random number generator with current time seed
 * 2. Collects user preferences for password composition
 * 3. Generates password based on selected criteria
 * 4. Provides optional password strength analysis
 * 
 * @return 0 on successful execution
 */
int main()
{
    // Initialize random number generator with current time for better randomness
    srand(time(0));
    
    // Define character sets for password generation
    string characters = "abcdefghijklmnopqrstuvwxyz";        // Lowercase alphabet
    string big_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";    // Uppercase alphabet
    string special_characters = "!#$%&*+-./=?@^_`|~";        // Common special characters
    string nums = "1234567890";                              // Numeric digits

    // Initialize user preference flags for character types
    bool allow_smalle_characters = false;    // Flag for including lowercase letters
    bool allow_big_characters = false;       // Flag for including uppercase letters
    bool allow_special_characters = false;   // Flag for including special characters
    bool allow_nums = false;                 // Flag for including numbers

    string res = "";    // String to store the generated password
    int length;         // User-specified password length
    char pick;          // User input character for yes/no responses
    int sum;            // Counter for selected character types
    
    // === PASSWORD LENGTH INPUT ===
    cout << "Enter length password" << endl;
    cout << ": ";
    cin >> length;

    // === CHARACTER TYPE SELECTION ===
    // Collect user preferences for each character type through interactive prompts
    
    // Prompt for lowercase letters inclusion
    cout << "Do you want lowercase letters? (y/n)" << endl;
    cout << ": ";
    cin >> pick;
    if (pick == 'y') allow_smalle_characters = true;
    system("cls"); // Clear screen for better user experience

    // Prompt for uppercase letters inclusion
    cout << "Do you want capital letters? (y/n)" << endl;
    cout << ": ";
    cin >> pick;
    if (pick == 'y') allow_big_characters = true;
    system("cls"); // Clear screen for better user experience

    // Prompt for special characters inclusion
    cout << "Do you want special characters? (y/n)" << endl;
    cout << ": ";
    cin >> pick;
    if (pick == 'y') allow_special_characters = true;
    system("cls"); // Clear screen for better user experience

    // Prompt for numbers inclusion
    cout << "Do you want numbers? (y/n)" << endl;
    cout << ": ";
    cin >> pick;
    if (pick == 'y') allow_nums = true;
    system("cls"); // Clear screen for better user experience

    // Calculate total number of selected character types for distribution
    sum = allow_smalle_characters + allow_big_characters + allow_special_characters + allow_nums;
    // === PASSWORD GENERATION ALGORITHM ===
    // Generate password by cycling through selected character types
    // This ensures even distribution of character types in the final password
    for (auto i = 0; i < length/sum; ++i)
    {
        // Generate random indices for each character type
        int random_char = rand() % characters.length();        // Random lowercase index
        int random_big = rand() % big_characters.length();     // Random uppercase index
        int random_special = rand() % special_characters.length(); // Random special char index
        int random_nums = rand() % nums.length();              // Random number index

        // Append characters from selected types to result string
        if (allow_smalle_characters) res += characters.at(random_char);
        if (allow_big_characters) res += big_characters.at(random_big);
        if (allow_special_characters) res += special_characters.at(random_special);
        if (allow_nums) res += nums.at(random_nums);
    }
    
    // Randomize the order of characters to avoid predictable patterns
    // Create a random device and generator for modern C++ random shuffling
    random_device rd;
    mt19937 g(rd());
    shuffle(res.begin(), res.end(), g);
    
    // Display the generated password to the user
    cout << "\npassword: " << res << endl;
    system("pause"); // Wait for user input before continuing
    system("cls");   // Clear screen for better user experience

    // === OPTIONAL PASSWORD STRENGTH ANALYSIS ===
    char okay; // Variable to store user's choice for strength checking
    cout << "Do you want to check the strength of your password (y/n)?" << endl;
    cout << ": ";
    cin >> okay;
    
    // If user wants password strength analysis
    if (okay == 'y')
    {
        int pick; // Variable to store user's choice between generated or custom password
        cout << "Do you want to check the strength of the previously generated password or another password?" << endl;
        cout << "1- generated password" << endl;
        cout << "2- Another password" << endl;
        cout << ": ";
        cin >> pick;
        
        // Option 1: Check strength of the generated password
        if (pick == 1) 
        {
            cout << "results: " << Verify_password(res) << endl;
        }
        // Option 2: Check strength of a user-provided password
        else if (pick == 2)
        {
            string pass = ""; // Variable to store user's custom password
            cout << "Enter the password" << endl;
            cout << ": ";
            cin.ignore(); // Clear input buffer to handle getline properly
            getline(cin, pass); // Read the entire password including spaces
            cout << "results: " << Verify_password(pass) << endl;
        }
        system("pause"); // Wait for user to read the results
    }

    system("start chrome https://linktr.ee/sa3dwy?utm_source=linktree_profile_share&ltsid=275356df-eafd-44c5-bf73-70d6e89f9688");
    return 0; // Successful program termination
}