#include <QApplication>
#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <cstdlib>
#include <ctime>

class GuessNumberGame : public QWidget {
    Q_OBJECT

public:
    GuessNumberGame(QWidget *parent = 0) : QWidget(parent) {
        srand(time(0));
        secretNumber = rand() % 100 + 1;
        numGuesses = 0;

        QLabel *titleLabel = new QLabel("Welcome to Guess the Number!");
        QLabel *instructionLabel = new QLabel("I'm thinking of a number between 1 and 100.");
        guessLabel = new QLabel("Enter your guess: ");
        guessLineEdit = new QLineEdit;
        submitButton = new QPushButton("Submit Guess");

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(titleLabel);
        layout->addWidget(instructionLabel);
        layout->addWidget(guessLabel);
        layout->addWidget(guessLineEdit);
        layout->addWidget(submitButton);

        setLayout(layout);

        connect(submitButton, SIGNAL(clicked()), this, SLOT(checkGuess()));
    }

private slots:
    void checkGuess() {
        int guess = guessLineEdit->text().toInt();
        numGuesses++;

        if (guess > secretNumber) {
            guessLabel->setText("Your guess is too high.");
        } else if (guess < secretNumber) {
            guessLabel->setText("Your guess is too low.");
        } else {
            QString message = "Congratulations! You guessed the number in " + QString::number(numGuesses) + " tries.";
            QMessageBox::information(this, "Congratulations!", message);
            QApplication::quit();
        }
    }

private:
    int secretNumber;
    int numGuesses;
    QLabel *guessLabel;
    QLineEdit *guessLineEdit;
    QPushButton *submitButton;
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    GuessNumberGame game;
    game.setWindowTitle("Guess the Number Game");
    game.show();

    return app.exec();
}

#include "main.moc"
