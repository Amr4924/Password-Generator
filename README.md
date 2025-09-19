# Password Generator & Strength Checker v1.0

A robust and user-friendly command-line application written in C++ that generates secure passwords and evaluates password strength according to modern security standards.

## 🔐 Features

- **Customizable Password Generation**: Generate passwords with specific character sets
- **Password Strength Analysis**: Comprehensive password strength evaluation
- **Interactive Interface**: User-friendly command-line interface
- **Multiple Character Sets**: Support for lowercase, uppercase, special characters, and numbers
- **Secure Randomization**: Uses proper random seed generation for enhanced security

## 📋 Table of Contents

- [Features](#-features)
- [Installation](#-installation)
- [Usage](#-usage)
- [Password Strength Criteria](#-password-strength-criteria)
- [Character Sets](#-character-sets)
- [Examples](#-examples)
- [Requirements](#-requirements)
- [Contributing](#-contributing)
- [License](#-license)

## 🚀 Installation

### Prerequisites
- C++ compiler (GCC, Clang, or MSVC)
- C++11 or later standard support

### Build Instructions

1. **Clone or download the repository**
   ```bash
   git clone <repository-url>
   cd password-generator
   ```

2. **Compile the application**
   
   **For Windows (Visual Studio):**
   ```cmd
   cl ConsoleApplication6.cpp /EHsc
   ```
   
   **For Linux/Mac (GCC):**
   ```bash
   g++ -std=c++11 ConsoleApplication6.cpp -o password_generator
   ```
   
   **For Windows (MinGW):**
   ```cmd
   g++ -std=c++11 ConsoleApplication6.cpp -o password_generator.exe
   ```

3. **Run the application**
   ```bash
   ./password_generator
   ```

## 💻 Usage

### Password Generation

1. **Start the application** and follow the interactive prompts
2. **Enter desired password length** (minimum 8 characters recommended)
3. **Select character types** to include:
   - Lowercase letters (a-z)
   - Uppercase letters (A-Z)
   - Special characters (!#$%&*+-./=?@^_`|~)
   - Numbers (0-9)
4. **Generated password** will be displayed with randomized character order

### Password Strength Checking

After generating a password, you can:
- Check the strength of the generated password
- Test strength of any custom password
- Receive detailed strength analysis results

## 🔒 Password Strength Criteria

The application evaluates passwords based on the following criteria:

| Strength Level | Requirements |
|---------------|--------------|
| **Very Strong** | ✅ All 4 character types + minimum 8 characters |
| **Strong** | ✅ 3 character types + minimum 8 characters |
| **Middle** | ✅ 2 character types + minimum 8 characters |
| **Weak** | ✅ 1 character type + minimum 8 characters |
| **Invalid** | ❌ Less than 8 characters or no valid characters |

### Character Types:
1. **Digits** (0-9)
2. **Lowercase letters** (a-z)
3. **Uppercase letters** (A-Z)
4. **Special characters** (!#$%&*+-./=?@^_`|~)

## 📝 Character Sets

The application uses the following character sets:

- **Lowercase**: `abcdefghijklmnopqrstuvwxyz`
- **Uppercase**: `ABCDEFGHIJKLMNOPQRSTUVWXYZ`
- **Special Characters**: `!#$%&*+-./=?@^_`|~`
- **Numbers**: `1234567890`

## 📖 Examples

### Example 1: Strong Password Generation
```
Enter length password: 16
Do you want lowercase letters? (y/n): y
Do you want capital letters? (y/n): y
Do you want special characters? (y/n): y
Do you want numbers? (y/n): y

Generated password: K9m#Px2@vN8$qR3!
Strength: Very Strong
```

### Example 2: Password Strength Check
```
Enter the password: MyPassword123!
Results: Very Strong
```

## ⚙️ Requirements

- **Operating System**: Windows, Linux, macOS
- **Compiler**: C++11 compatible compiler
- **Memory**: Minimal (< 1MB)
- **Dependencies**: Standard C++ library only

## 🛠️ Technical Details

### Algorithm Features
- **Secure Random Generation**: Uses `srand(time(0))` for seed initialization
- **Character Distribution**: Ensures even distribution across selected character sets
- **Randomization**: Implements `std::shuffle` for final password randomization
- **Input Validation**: Comprehensive validation for all user inputs

### Performance
- **Generation Speed**: Instantaneous for passwords up to 1000+ characters
- **Memory Efficient**: Minimal memory footprint
- **Cross-Platform**: Compatible with major operating systems

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. **Fork the repository**
2. **Create a feature branch** (`git checkout -b feature/AmazingFeature`)
3. **Commit your changes** (`git commit -m 'Add some AmazingFeature'`)
4. **Push to the branch** (`git push origin feature/AmazingFeature`)
5. **Open a Pull Request**

### Contribution Guidelines
- Follow C++ best practices and coding standards
- Add comments for complex logic
- Test your changes thoroughly
- Update documentation as needed

## 📄 License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 🔗 Links

- **Issues**: [Report bugs or request features](https://github.com/username/repository/issues)
- **Discussions**: [Join the community discussion](https://github.com/username/repository/discussions)

## 📞 Support

If you encounter any issues or have questions:

1. Check the [Issues](https://github.com/username/repository/issues) page
2. Create a new issue with detailed information
3. Include your operating system and compiler information

---

**Made with ❤️ for password security**

*Version 1.0 - Built with C++ for maximum performance and security*