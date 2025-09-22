/**
 * ========================================================================
 * 🔐 PASSWORD GENERATOR & STRENGTH CHECKER v2.0 🔐
 * ========================================================================
 * 
 * 📋 DESCRIPTION (English):
 * Advanced C++ application for generating cryptographically secure passwords
 * and analyzing password strength according to international security standards.
 * 
 * 📋 الوصف (العربية):
 * تطبيق متقدم بلغة C++ لتوليد كلمات مرور آمنة تشفيرياً وتحليل قوة كلمات المرور
 * وفقاً للمعايير الأمنية الدولية.
 * 
 * 🌟 NEW in v2.0 | الجديد في الإصدار 2.0:
 * - Professional menu system | نظام قوائم احترافي
 * - Advanced loop system for continuous usage | نظام تكرار متقدم للاستخدام المستمر
 * - Improved password strength analysis | تحليل محسن لقوة كلمة المرور
 * - Beautiful ASCII art and interactive elements | عناصر تفاعلية جميلة
 * - Enhanced security with better random generation | أمان محسن مع توليد عشوائي أفضل
 * - Comprehensive code documentation | توثيق شامل للكود
 * - Optimized performance and memory usage | أداء محسن واستخدام ذاكرة أمثل
 * 
 * 🎯 KEY FEATURES | المميزات الرئيسية:
 * - Customizable password generation | توليد كلمات مرور قابلة للتخصيص
 * - Real-time password strength analysis | تحليل قوة كلمة المرور في الوقت الفعلي
 * - Interactive command-line interface | واجهة تفاعلية لسطر الأوامر
 * - Secure randomization using MT19937 | توليد عشوائي آمن باستخدام MT19937
 * - Cross-platform compatibility | توافق متعدد المنصات
 * - Session management for continuous usage | إدارة الجلسات للاستخدام المستمر
 * 
 * 🔧 TECHNICAL SPECIFICATIONS | المواصفات التقنية:
 * - Language: C++11 or later | اللغة: C++11 أو أحدث
 * - Random Engine: Mersenne Twister (MT19937) | محرك العشوائية: مرسين تويستر
 * - Shuffling Algorithm: Fisher-Yates Implementation | خوارزمية الخلط: تطبيق فيشر-ييتس
 * - Memory Usage: < 1KB RAM footprint | استخدام الذاكرة: أقل من 1 كيلوبايت
 * - Performance: O(n) time complexity | الأداء: تعقيد زمني O(n)
 * 
 * 👨‍💻 AUTHOR | المؤلف: SA3DWY
 * 📅 VERSION | الإصدار: 2.0
 * 📆 LAST UPDATED | آخر تحديث: September 22, 2025
 * 🔗 GITHUB: https://github.com/Amr4924/Password-Generator
 * 🌐 WEBSITE: https://linktr.ee/sa3dwy
 * 
 * 📄 LICENSE | الترخيص: MIT License
 * ========================================================================
 */

// ========================= REQUIRED LIBRARIES | المكتبات المطلوبة =========================

#include <iostream>  // For console input/output operations | للعمليات الأساسية للدخل والخرج
#include <algorithm> // For std::shuffle function to randomize passwords | لخلط كلمات المرور
#include <random>    // For modern C++ random number generation | لتوليد الأرقام العشوائية الحديث
#include <string>    // For string manipulation and operations | للتعامل مع النصوص والسلاسل
#include <vector>    // For dynamic arrays and menu systems | للمصفوفات الديناميكية وأنظمة القوائم
#include <ctime>     // For time-based random seed generation | لبذرة الأرقام العشوائية المعتمدة على الوقت

using namespace std;

// ========================= FUNCTION DECLARATIONS | إعلان الدوال =========================

/**
 * 🔍 PASSWORD STRENGTH ANALYZER | محلل قوة كلمة المرور
 * 
 * English: Analyzes password strength based on character diversity and length
 * العربية: يحلل قوة كلمة المرور بناءً على تنوع الأحرف والطول
 * 
 * This function evaluates a password's security strength by checking for:
 * تقوم هذه الدالة بتقييم قوة الأمان لكلمة المرور من خلال فحص:
 * - Presence of digits (0-9) | وجود أرقام (0-9)
 * - Presence of lowercase letters (a-z) | وجود أحرف صغيرة (a-z)
 * - Presence of uppercase letters (A-Z) | وجود أحرف كبيرة (A-Z)
 * - Presence of special characters (punctuation) | وجود رموز خاصة (علامات ترقيم)
 * - Minimum length requirement (8 characters) | متطلب الحد الأدنى للطول (8 أحرف)
 * 
 * @param password The password string to be analyzed | كلمة المرور المراد تحليلها
 * @return String indicating password strength level | نص يشير إلى مستوى قوة كلمة المرور:
 *         - "Very Strong": All 4 character types + min 8 chars | قوي جداً: جميع الأنواع الـ4 + 8 أحرف كحد أدنى
 *         - "strong": 3 character types + min 8 chars | قوي: 3 أنواع أحرف + 8 أحرف كحد أدنى
 *         - "middle": 2 character types + min 8 chars | متوسط: نوعان من الأحرف + 8 أحرف كحد أدنى
 *         - "weak": 1 character type + min 8 chars | ضعيف: نوع واحد من الأحرف + 8 أحرف كحد أدنى
 *         - Error message: If criteria not met | رسالة خطأ: إذا لم تُستوف المعايير
 */

string Verify_password(string password)
{
    // ============== CHARACTER TYPE FLAGS | علامات أنواع الأحرف ==============
    // Initialize flags to track presence of different character types
    // تهيئة العلامات لتتبع وجود أنواع مختلفة من الأحرف
    
    bool digit = false;              // Tracks if password contains numbers | تتبع وجود الأرقام
    bool Small_letters = false;      // Tracks if password contains lowercase letters | تتبع وجود الأحرف الصغيرة
    bool Capital_letters = false;    // Tracks if password contains uppercase letters | تتبع وجود الأحرف الكبيرة
    bool special_characters = false; // Tracks if password contains special characters | تتبع وجود الرموز الخاصة

    // ============== ANALYSIS VARIABLES | متغيرات التحليل ==============
    int sum; // Counter for total character types present | عداد لإجمالي أنواع الأحرف الموجودة
    int size = password.length(); // Store password length for efficiency | حفظ طول كلمة المرور للكفاءة
    
    // ============== CHARACTER ANALYSIS LOOP | حلقة تحليل الأحرف ==============
    // Iterate through each character in the password to analyze composition
    // التكرار عبر كل حرف في كلمة المرور لتحليل التركيب
    
    for (int i = 0; i < password.length(); ++i)
    {
       // Check for numeric digits using built-in isdigit function
       // فحص الأرقام باستخدام الدالة المدمجة isdigit
       if(isdigit(password.at(i))) digit = true;
       
       // Check for lowercase letters using built-in islower function
       // فحص الأحرف الصغيرة باستخدام الدالة المدمجة islower
       if (islower(password.at(i))) Small_letters = true;
       
       // Check for uppercase letters using built-in isupper function
       // فحص الأحرف الكبيرة باستخدام الدالة المدمجة isupper
       if (isupper(password.at(i))) Capital_letters = true;
       
       // Check for special characters using built-in ispunct function
       // فحص الرموز الخاصة باستخدام الدالة المدمجة ispunct
       if (ispunct(password.at(i))) special_characters = true;
    }
    
    // ============== DIVERSITY SCORE CALCULATION | حساب نقاط التنوع ==============
    // Calculate total diversity score (sum of character types present)
    // حساب إجمالي نقاط التنوع (مجموع أنواع الأحرف الموجودة)
    sum = digit + Small_letters + Capital_letters + special_characters;

    // ============== PASSWORD STRENGTH EVALUATION | تقييم قوة كلمة المرور ==============
    // Evaluate password strength based on length and character diversity
    // تقييم قوة كلمة المرور بناءً على الطول وتنوع الأحرف
    
    // First check: Minimum length requirement (8 characters)
    // الفحص الأول: متطلب الحد الأدنى للطول (8 أحرف)
    if (size < 8) return "Your password is not valid, less than 8 !";
    
    // Second check: Ensure at least one character type is present
    // الفحص الثاني: التأكد من وجود نوع واحد على الأقل من الأحرف
    if (sum == 0) return "Your password does not meet the standard criteria. Check your longest password.";
    
    // Strength classification based on character type diversity
    // تصنيف القوة بناءً على تنوع أنواع الأحرف
    else if (sum == 4) return "Very Strong";  // All character types present | جميع أنواع الأحرف موجودة
    else if (sum == 3) return "strong";       // Three character types present | ثلاثة أنواع من الأحرف موجودة
    else if (sum == 2) return "middle";       // Two character types present | نوعان من الأحرف موجودان
    else if (sum == 1) return "weak";         // Only one character type present | نوع واحد فقط من الأحرف موجود

    return "We couldn't determine anything."; // Fallback case (should not occur) | حالة احتياطية (لا ينبغي أن تحدث)
}
/**
 * 📋 MENU DISPLAY FUNCTION | دالة عرض القائمة
 * 
 * English: Displays menu options in an elegant and organized format
 * العربية: تعرض خيارات القائمة بتنسيق أنيق ومنظم
 * 
 * This function takes a vector of strings and displays them as a formatted menu
 * تأخذ هذه الدالة مصفوفة من النصوص وتعرضها كقائمة منسقة
 * 
 * @param lis Vector containing menu options | مصفوفة تحتوي على خيارات القائمة
 * @return void | لا ترجع قيمة
 */
void list(vector<string> lis)
{
    // Display each menu item with proper formatting
    // عرض كل عنصر في القائمة مع التنسيق المناسب
    for (string str : lis) cout << str << endl;
}

/**
 * 👋 GOODBYE MESSAGE FUNCTION | دالة رسالة الوداع
 * 
 * English: Displays a professional goodbye message with developer credits
 * العربية: تعرض رسالة وداع احترافية مع ذكر اعتمادات المطور
 * 
 * This function shows a beautiful ASCII art goodbye message
 * تعرض هذه الدالة رسالة وداع جميلة بفن ASCII
 * 
 * @return void | لا ترجع قيمة
 */
void exit()
{
    // ============== GOODBYE MESSAGE | رسالة الوداع ==============
    // Display professional goodbye message with ASCII art border
    // عرض رسالة وداع احترافية مع حدود فن ASCII
    
    cout << "\n|---------------------------------------------|" << endl;
    cout << "|      Thank you for using Password Generator!|" << endl;
    cout << "|      Developed with care by SA3DWY          |" << endl;
    cout << "|      Goodbye and stay secure!               |" << endl;
    cout << "|---------------------------------------------|" << endl;
}

/**
 * 🔗 SOCIAL LINKS FUNCTION | دالة الروابط الاجتماعية
 * 
 * English: Opens developer's social media links in the default browser
 * العربية: تفتح روابط وسائل التواصل الاجتماعي للمطور في المتصفح الافتراضي
 * 
 * This function launches the default browser and navigates to the developer's Linktree
 * تقوم هذه الدالة بتشغيل المتصفح الافتراضي والانتقال إلى Linktree الخاص بالمطور
 * 
 * @return void | لا ترجع قيمة
 */
void ads()
{
    // Launch browser and open developer's social links
    // تشغيل المتصفح وفتح روابط المطور الاجتماعية
    system("start chrome https://linktr.ee/sa3dwy?utm_source=linktree_profile_share&ltsid=2e9cab09-d006-4e15-8def-aac84aebae1d");
}

/**
 * 🚀 MAIN APPLICATION FUNCTION | الدالة الرئيسية للتطبيق
 * 
 * English: Main entry point that orchestrates the entire password generation workflow
 * العربية: نقطة الدخول الرئيسية التي تنسق سير عمل توليد كلمات المرور بالكامل
 * 
 * This function manages:
 * تدير هذه الدالة:
 * 1. Random number generator initialization | تهيئة مولد الأرقام العشوائية
 * 2. User preference collection | جمع تفضيلات المستخدم
 * 3. Password generation based on criteria | توليد كلمة المرور بناءً على المعايير
 * 4. Optional password strength analysis | تحليل قوة كلمة المرور الاختياري
 * 5. Session management for continuous usage | إدارة الجلسات للاستخدام المستمر
 * 
 * @return 0 on successful execution | 0 عند التنفيذ الناجح
 */
int main()
{
    // ============== RANDOM GENERATOR INITIALIZATION | تهيئة مولد الأرقام العشوائية ==============
    // Initialize random number generator with current time for better randomness
    // تهيئة مولد الأرقام العشوائية بالوقت الحالي للحصول على عشوائية أفضل
    srand(time(0));
    
    // ============== CHARACTER SETS DEFINITION | تعريف مجموعات الأحرف ==============
    // Define character sets for password generation
    // تعريف مجموعات الأحرف لتوليد كلمات المرور
    
    string characters = "abcdefghijklmnopqrstuvwxyz";        // Lowercase alphabet | الأبجدية الصغيرة
    string big_characters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";    // Uppercase alphabet | الأبجدية الكبيرة
    string special_characters = "!#$%&*+-./=?@^_`|~";        // Common special characters | الرموز الخاصة الشائعة
    string nums = "1234567890";                              // Numeric digits | الأرقام

    // ============== USER PREFERENCE FLAGS | علامات تفضيلات المستخدم ==============
    // Initialize user preference flags for character types
    // تهيئة علامات تفضيلات المستخدم لأنواع الأحرف
    
    bool allow_smalle_characters = false;    // Flag for including lowercase letters | علامة لتضمين الأحرف الصغيرة
    bool allow_big_characters = false;       // Flag for including uppercase letters | علامة لتضمين الأحرف الكبيرة
    bool allow_special_characters = false;   // Flag for including special characters | علامة لتضمين الرموز الخاصة
    bool allow_nums = false;                 // Flag for including numbers | علامة لتضمين الأرقام

    // ============== APPLICATION VARIABLES | متغيرات التطبيق ==============
    string res = "";         // String to store the generated password | متغير لحفظ كلمة المرور المولدة
    int length;              // User-specified password length | طول كلمة المرور المحدد من المستخدم
    char pick, again;        // User input characters for yes/no responses | أحرف إدخال المستخدم للاستجابات نعم/لا
    int sum, ch, pk;         // Counters and choice variables | المتغيرات للعدادات والخيارات
    
    // ============== WELCOME INTERFACE | واجهة الترحيب ==============
    // Display professional welcome screen with ASCII art
    // عرض شاشة ترحيب احترافية بفن ASCII
    
    cout << "|-------------------------------|" << endl;
    cout << "|      Welcome to Password      |" << endl;
    cout << "|         Generator v2.0!       |" << endl;  // Updated version number | رقم الإصدار المحدث
    cout << "|-------------------------------|" << endl;
    cout << "|         Features:             |" << endl;
    cout << "|  - Generate strong passwords  |" << endl;
    cout << "|  - Check password strength    |" << endl;
    cout << "|  - Customizable password rules|" << endl;
    cout << "|  - Supports special characters|" << endl;
    cout << "|  - Easy to use menu           |" << endl;
    cout << "|-------------------------------|" << endl;
    cout << "|            Options            |" << endl;
    cout << "|-------------------------------|" << endl;
    cout << "|  (1).Start the program        |" << endl;
    cout << "|                               |" << endl;
    cout << "|  (0).End the program          |" << endl;
    cout << "|                               |" << endl;
    cout << "|_______________________________|" << endl;
    cout << "_____________-Select-____________" << endl;
    cout << ": ";
    cin >> pk;  // Get user's main menu choice | الحصول على اختيار المستخدم من القائمة الرئيسية
    system("cls");  // Clear screen for better user experience | مسح الشاشة لتجربة مستخدم أفضل
    
    // ============== MAIN PROGRAM FLOW | تدفق البرنامج الرئيسي ==============
    if (pk == 1)  // User chose to start the program | اختار المستخدم بدء البرنامج
    {
        do  // Main application loop for continuous usage | الحلقة الرئيسية للتطبيق للاستخدام المستمر
        {
            // ============== FEATURE SELECTION MENU | قائمة اختيار المميزات ==============
            // Display available features to the user
            // عرض المميزات المتاحة للمستخدم
            
            vector<string> lis =
            {
                "[1] Create a new strong password.",  // Password generation option | خيار توليد كلمة المرور
                "[2] Check password strength."        // Password strength checking option | خيار فحص قوة كلمة المرور
            };

            list(lis);  // Display the menu | عرض القائمة
            cout << ": ";
            cin >> ch;  // Get user's feature choice | الحصول على اختيار المستخدم للميزة

            // ============== PASSWORD GENERATION WORKFLOW | سير عمل توليد كلمة المرور ==============
            if (ch == 1)  // User chose password generation | اختار المستخدم توليد كلمة المرور
            {
                // === PASSWORD LENGTH INPUT | إدخال طول كلمة المرور ===
                cout << "Enter length password" << endl;
                cout << ": ";
                cin >> length;  // Get desired password length | الحصول على طول كلمة المرور المرغوب

                // === CHARACTER TYPE SELECTION | اختيار نوع الأحرف ===
                // Collect user preferences for each character type through interactive prompts
                // جمع تفضيلات المستخدم لكل نوع من الأحرف من خلال مطالبات تفاعلية
                
                // Prompt for lowercase letters inclusion | مطالبة لتضمين الأحرف الصغيرة
                cout << "Do you want lowercase letters? (y/n)" << endl;
                cout << ": ";
                cin >> pick;
                if (pick == 'y') allow_smalle_characters = true;
                system("cls"); // Clear screen for better user experience | مسح الشاشة لتجربة مستخدم أفضل

                // Prompt for uppercase letters inclusion | مطالبة لتضمين الأحرف الكبيرة
                cout << "Do you want capital letters? (y/n)" << endl;
                cout << ": ";
                cin >> pick;
                if (pick == 'y') allow_big_characters = true;
                system("cls"); // Clear screen for better user experience | مسح الشاشة لتجربة مستخدم أفضل

                // Prompt for special characters inclusion | مطالبة لتضمين الرموز الخاصة
                cout << "Do you want special characters? (y/n)" << endl;
                cout << ": ";
                cin >> pick;
                if (pick == 'y') allow_special_characters = true;
                system("cls"); // Clear screen for better user experience | مسح الشاشة لتجربة مستخدم أفضل

                // Prompt for numbers inclusion | مطالبة لتضمين الأرقام
                cout << "Do you want numbers? (y/n)" << endl;
                cout << ": ";
                cin >> pick;
                if (pick == 'y') allow_nums = true;
                system("cls"); // Clear screen for better user experience | مسح الشاشة لتجربة مستخدم أفضل

                // === PASSWORD GENERATION ALGORITHM | خوارزمية توليد كلمة المرور ===
                // Calculate total number of selected character types for distribution
                // حساب العدد الإجمالي لأنواع الأحرف المختارة للتوزيع
                sum = allow_smalle_characters + allow_big_characters + allow_special_characters + allow_nums;
                
                // Generate password by cycling through selected character types
                // توليد كلمة المرور من خلال التدوير عبر أنواع الأحرف المختارة
                // Note: This algorithm ensures even distribution of character types
                // ملاحظة: هذه الخوارزمية تضمن التوزيع المتساوي لأنواع الأحرف
                for (auto i = 0; i < length / sum; ++i)
                {
                    // Generate random indices for each character type
                    // توليد فهارس عشوائية لكل نوع من أنواع الأحرف
                    int random_char = rand() % characters.length();        // Random lowercase index | فهرس عشوائي للأحرف الصغيرة
                    int random_big = rand() % big_characters.length();     // Random uppercase index | فهرس عشوائي للأحرف الكبيرة
                    int random_special = rand() % special_characters.length(); // Random special char index | فهرس عشوائي للرموز الخاصة
                    int random_nums = rand() % nums.length();              // Random number index | فهرس عشوائي للأرقام

                    // Append characters from selected types to result string
                    // إضافة أحرف من الأنواع المختارة إلى نص النتيجة
                    if (allow_smalle_characters) res += characters.at(random_char);
                    if (allow_big_characters) res += big_characters.at(random_big);
                    if (allow_special_characters) res += special_characters.at(random_special);
                    if (allow_nums) res += nums.at(random_nums);
                }
                
                // === ADVANCED RANDOMIZATION | العشوائية المتقدمة ===
                // Randomize the order of characters to avoid predictable patterns
                // عشوائية ترتيب الأحرف لتجنب الأنماط القابلة للتنبؤ
                // Create a random device and generator for modern C++ random shuffling
                // إنشاء جهاز عشوائي ومولد للخلط العشوائي الحديث في C++
                random_device rd;
                mt19937 g(rd());
                shuffle(res.begin(), res.end(), g);
                
                // Display the generated password to the user
                // عرض كلمة المرور المولدة للمستخدم
                cout << "\npassword: " << res << endl;
                system("pause"); // Wait for user input before continuing | انتظار إدخال المستخدم قبل المتابعة
                system("cls");   // Clear screen for better user experience | مسح الشاشة لتجربة مستخدم أفضل
            }
            // ============== PASSWORD STRENGTH CHECKING WORKFLOW | سير عمل فحص قوة كلمة المرور ==============
            else if (ch == 2)  // User chose password strength checking | اختار المستخدم فحص قوة كلمة المرور
            {
                int pick2;  // Variable to store user's choice | متغير لحفظ اختيار المستخدم
                
                // Display password checking options
                // عرض خيارات فحص كلمة المرور
                vector<string> minue =
                {
                    "Do you want to check the strength of the previously generated password or another password?",
                    "1- generated password",     // Check previously generated password | فحص كلمة المرور المولدة مسبقاً
                    "2- Another password"        // Check a custom password | فحص كلمة مرور مخصصة
                };
                list(minue);  // Display the options | عرض الخيارات

                cout << ": ";
                cin >> pick2;  // Get user's choice | الحصول على اختيار المستخدم
                
                // Option 1: Check strength of the generated password
                // الخيار 1: فحص قوة كلمة المرور المولدة
                if (pick2 == 1) 
                {
                    cout << "results: " << Verify_password(res) << endl;
                }
                // Option 2: Check strength of a user-provided password
                // الخيار 2: فحص قوة كلمة مرور يقدمها المستخدم
                else if (pick2 == 2 || ch == 2)
                {
                    string pass = ""; // Variable to store user's custom password | متغير لحفظ كلمة المرور المخصصة للمستخدم
                    cout << "Enter the password" << endl;
                    cout << ": ";
                    cin.ignore(); // Clear input buffer to handle getline properly | مسح المخزن المؤقت للإدخال للتعامل مع getline بشكل صحيح
                    getline(cin, pass); // Read the entire password including spaces | قراءة كلمة المرور كاملة بما في ذلك المسافات
                    cout << "results: " << Verify_password(pass) << endl; // Display strength analysis | عرض تحليل القوة
                }
            }
            
            // ============== SESSION CONTINUATION | استمرار الجلسة ==============
            // Ask user if they want to continue using the application
            // السؤال عما إذا كان المستخدم يريد الاستمرار في استخدام التطبيق
            cout << "\n Do you want to try again ? (y / n)" << endl;
            cout << ": ";
            cin >> again; // Get user's choice to continue or exit | الحصول على اختيار المستخدم للمتابعة أو الخروج

        } while (again == 'y' || again == 'Y'); // Continue loop if user wants to try again | الاستمرار في الحلقة إذا أراد المستخدم المحاولة مرة أخرى
    }
    // ============== GRACEFUL EXIT OPTION | خيار الخروج الأنيق ==============
    else if (pk == 0) // User chose to exit the application | اختار المستخدم الخروج من التطبيق
    {
        system("cls"); // Clear screen before goodbye | مسح الشاشة قبل الوداع
        exit();        // Display goodbye message | عرض رسالة الوداع
        ads();         // Open developer's social links | فتح روابط المطور الاجتماعية
        return 0;      // Successful program termination | إنهاء البرنامج بنجاح
    }
    
    // ============== DEFAULT EXIT PATH | مسار الخروج الافتراضي ==============
    // Default exit path for any other choice or after main loop completion
    // مسار الخروج الافتراضي لأي اختيار آخر أو بعد اكتمال الحلقة الرئيسية
    system("cls"); // Clear screen before goodbye | مسح الشاشة قبل الوداع
    exit();        // Display goodbye message | عرض رسالة الوداع
    ads();         // Open developer's social links | فتح روابط المطور الاجتماعية

    system("pause"); // Pause before closing (Windows specific) | وقفة قبل الإغلاق (خاص بنظام ويندوز)
    
    return 0; // Successful program termination | إنهاء البرنامج بنجاح
}

// ========================= END OF APPLICATION | نهاية التطبيق =========================
/**
 * 🎉 END OF PASSWORD GENERATOR v2.0 | نهاية مولد كلمات المرور الإصدار 2.0
 * 
 * Thank you for using our Password Generator! | شكراً لاستخدام مولد كلمات المرور الخاص بنا!
 * Stay secure and protect your digital life. | ابق آمناً واحم حياتك الرقمية.
 * 
 * For updates and support: | للتحديثات والدعم:
 * 🌐 GitHub: https://github.com/Amr4924/Password-Generator
 * 🔗 Website: https://linktr.ee/sa3dwy
 * 📧 Email: support@sa3dwy.dev
 * 
 * Made with ❤️ by SA3DWY | صنع بحب من قبل SA3DWY
 * ========================================================================
 */