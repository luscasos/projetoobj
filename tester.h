#ifndef TESTER_H
#define TESTER_H
#include <QApplication>

#include <QMessageBox>
#include <QInputDialog>

#include <QIcon>

#include <QApplication>

#include <QMessageBox>
#include <QInputDialog>

#include <QIcon>

class Tester : public QWidget
{
public:
    Tester();
  void test()
  {
    QMessageBox::information(
        this,
        tr("batata"),
        tr("An information message.") );

    QMessageBox::warning(
        this,
        tr("Application Name"),
        tr("A warning message.") );

    QMessageBox::critical(
      this,
      tr("Application Name"),
      tr("A critical message.") );

    switch( QMessageBox::question(
                this,
                tr("Application Name"),
                tr("An information message."),

                QMessageBox::Yes |
                QMessageBox::No |
                QMessageBox::Cancel,

                QMessageBox::Cancel ) )
    {
      case QMessageBox::Yes:
        qDebug( "yes" );
        break;
      case QMessageBox::No:
        qDebug( "no" );
        break;
      case QMessageBox::Cancel:
        qDebug( "cancel" );
        break;
      default:
        qDebug( "close" );
        break;
    }

    setWindowIcon( QIcon("cut.png") );

//{
//    bool ok;
//    int value = QInputDialog::getInt(
//                    this,
//                    tr("Integer"),
//                    tr("Enter an angle:"),
//                    90,
//                    0,
//                    360,
//                    1,
//                    &ok );
//    if( ok )
//    {
//    }
//}

{
    bool ok;
    QStringList items;
    items << tr("Foo") << tr("Bar") << tr("Baz");
    QString item = QInputDialog::getItem(
                      this,
                      tr("Item"),
                      tr("Pick an item:"),
                      items,
                      0,
                      false,
                      &ok );
    if( ok && !item.isEmpty() )
    {
    }
}

{
    bool ok;
    QString text = QInputDialog::getText(
                      this,
                      tr("String"),
                      tr("Enter a city name:"),
                      QLineEdit::Normal,
                      tr("Alings?s"),
                      &ok );
    if( ok && !text.isEmpty() )
    {
    }
}
  }
};

//int main( int argc, char **argv )
//{
//  QApplication app( argc, argv );

//  Tester t;
//  t.test();

//  return 0;
//}

#endif // TESTER_H
