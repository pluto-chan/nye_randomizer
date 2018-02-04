#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QString"
#include "vector"
#include <fstream>
#include "QTime"
#include <QTimer>
#include <math.h>

using namespace std;

const int played_tracks_count = 4;
const int draft_count = 12;

vector<string> set8;
vector<string> set9;
vector<string> set10;
vector<string> set11;
vector<string> set12;
vector<string> set13;

vector<vector<string>> sets;

vector<string> draft_tracks;
vector<string> pick_tracks;

int pick_count = 0;
int ban_count = 0;

QPushButton* draft[12];
QPushButton* bans[12];
QLabel* picks[4];

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//ху

    draft[0] = ui->t;
    draft[1] = ui->t_2;
    draft[2] = ui->t_3;
    draft[3] = ui->t_4;
    draft[4] = ui->t_5;
    draft[5] = ui->t_6;
    draft[6] = ui->t_7;
    draft[7] = ui->t_8;
    draft[8] = ui->t_9;
    draft[9] = ui->t_10;
    draft[10] = ui->t_11;
    draft[11] = ui->t_12;

    bans[0] = ui->ban;
    bans[1] = ui->ban_2;
    bans[2] = ui->ban_3;
    bans[3] = ui->ban_4;
    bans[4] = ui->ban_5;
    bans[5] = ui->ban_6;
    bans[6] = ui->ban_7;
    bans[7] = ui->ban_8;
    bans[8] = ui->ban_9;
    bans[9] = ui->ban_10;
    bans[10] = ui->ban_11;
    bans[11] = ui->ban_12;


    picks[0] = ui->p;
    picks[1] = ui->p_2;
    picks[2] = ui->p_3;
    picks[3] = ui->p_4;

    for (int i = 0; i < played_tracks_count; i++)
    {
        picks[i]->setAlignment(Qt::AlignCenter);
        picks[i]->setText("");
    }

    for (int i = 0; i < draft_count; i++)
    {

        draft[i]->setText("");
    }

    QString line;
    ifstream shit;
    string dick = "";

    shit.open("/Users/plutos/NYE/set8.txt");
    getline(shit, dick);
            do
            {
                set8.push_back(dick);
                getline(shit, dick);
            } while (dick != "end");

    shit.close();

    shit.open("/Users/plutos/NYE/set9.txt");
    getline(shit, dick);
            do
            {
                set9.push_back(dick);
                getline(shit, dick);
            } while (dick != "end");

    shit.close();

    shit.open("/Users/plutos/NYE/set10.txt");
    getline(shit, dick);
            do
            {
                set10.push_back(dick);
                getline(shit, dick);
            } while (dick != "end");

    shit.close();

    shit.open("/Users/plutos/NYE/set11.txt");
    getline(shit, dick);
            do
            {
                set11.push_back(dick);
                getline(shit, dick);
            } while (dick != "end");

    shit.close();

    shit.open("/Users/plutos/NYE/set12.txt");
    getline(shit, dick);
            do
            {
                set12.push_back(dick);
                getline(shit, dick);
            } while (dick != "end");

    shit.close();

    shit.open("/Users/plutos/NYE/set13.txt");
    getline(shit, dick);
            do
            {
                set13.push_back(dick);
                getline(shit, dick);
            } while (dick != "end");

    shit.close();

    sets.push_back(set8);
    sets.push_back(set9);
    sets.push_back(set10);
    sets.push_back(set11);
    sets.push_back(set12);
    sets.push_back(set13);
}

MainWindow::~MainWindow()
{
    delete ui;
}

/*void MainWindow::track_selected (QString tr_name)
{
    ui->pick->setText(tr_name);
}
*/
void MainWindow::on_b1_clicked()
{

}

void MainWindow::on_t_clicked()
{
    ui->t->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t->setEnabled(false);
    picks[pick_count]->setText(ui->t->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_roll_clicked()
{
    pick_count = 0;
    ban_count = 0;


    for (int i = 0; i < played_tracks_count; i++)
    {
        picks[i]->setText("");
    }

    for (int i = 0; i < draft_count; i++)
    {
        draft[i]->setEnabled(true);
        bans[i]->setEnabled(true);
        draft[i]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #2A5530; min-width: 80px; color: #FFFFFF; font: 22px; font-family: Pacifico; background-image: url(:/track.png);");
    }


    QTime midnight(0,0,0);
    qsrand(midnight.secsTo(QTime::currentTime()));
    for (int i = 0; i < 6; i++)
    {


        QString trName;

        int trackNum2 = -1;
        int trackNum = qrand()%sets[i].size();

        do
                trackNum2 = qrand()%sets[i].size();
        while (trackNum == trackNum2);

        trName = QString::fromStdString(sets[i][trackNum]);
        draft[i*2]->setText(trName);
        trName = QString::fromStdString(sets[i][trackNum2]);
        draft[i*2+1]->setText(trName);
    }
}

void MainWindow::on_ban_clicked()
{
    ui->t->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban->setEnabled(false);

}

void MainWindow::on_ban_2_clicked()
{
    ui->t_2->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_2->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_2->setEnabled(false);
}

void MainWindow::on_ban_3_clicked()
{
    ui->t_3->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_3->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_3->setEnabled(false);
}

void MainWindow::on_ban_4_clicked()
{
    ui->t_4->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_4->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_4->setEnabled(false);
}



void MainWindow::on_ban_5_clicked()
{
    ui->t_5->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_5->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_5->setEnabled(false);
}

void MainWindow::on_ban_6_clicked()
{
    ui->t_6->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_6->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_6->setEnabled(false);
}

void MainWindow::on_ban_7_clicked()
{
    ui->t_7->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_7->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_7->setEnabled(false);
}


void MainWindow::on_ban_8_clicked()
{
    ui->t_8->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_8->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_8->setEnabled(false);
}


void MainWindow::on_ban_9_clicked()
{
    ui->t_9->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_9->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_9->setEnabled(false);
}


void MainWindow::on_ban_10_clicked()
{
    ui->t_10->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_10->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_10->setEnabled(false);
}

void MainWindow::on_ban_12_clicked()
{
    ui->t_11->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_11->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_12->setEnabled(false);
}

void MainWindow::on_ban_11_clicked()
{
    ui->t_12->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_12->setEnabled(false);
    ban_count++;

    if (ban_count == draft_count - played_tracks_count)
    {
        QTime midnight(0,0,0);
        qsrand(midnight.secsTo(QTime::currentTime()));

        for (int j = 0; j < played_tracks_count - pick_count; j++)
        {

            int fill_num;
            do
                fill_num = qrand()%draft_count;
            while (draft[fill_num]->isEnabled() == false);

            picks[pick_count+j]->setText(draft[fill_num]->text());
            draft[fill_num]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[fill_num]->setEnabled(false);
        }
    }
    ui->ban_11->setEnabled(false);
}

void MainWindow::on_t_6_clicked()
{
    ui->t_6->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_6->setEnabled(false);
    picks[pick_count]->setText(ui->t_6->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_2_clicked()
{
    ui->t_2->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_2->setEnabled(false);
    picks[pick_count]->setText(ui->t_2->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_3_clicked()
{
    ui->t_3->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_3->setEnabled(false);
    picks[pick_count]->setText(ui->t_3->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_4_clicked()
{
    ui->t_4->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_4->setEnabled(false);
    picks[pick_count]->setText(ui->t_4->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}



void MainWindow::on_t_5_clicked()
{
    ui->t_5->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_5->setEnabled(false);
    picks[pick_count]->setText(ui->t_5->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}


void MainWindow::on_t_7_clicked()
{
    ui->t_7->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_7->setEnabled(false);
    picks[pick_count]->setText(ui->t_7->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}


void MainWindow::on_t_8_clicked()
{
    ui->t_8->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_8->setEnabled(false);
    picks[pick_count]->setText(ui->t_8->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_9_clicked()
{
    ui->t_9->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_9->setEnabled(false);
    picks[pick_count]->setText(ui->t_9->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_10_clicked()
{
    ui->t_10->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_10->setEnabled(false);
    picks[pick_count]->setText(ui->t_10->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_11_clicked()
{
    ui->t_11->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_11->setEnabled(false);
    picks[pick_count]->setText(ui->t_11->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_t_12_clicked()
{
    ui->t_12->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
    ui->t_12->setEnabled(false);
    picks[pick_count]->setText(ui->t_12->text());
    pick_count++;

    if (pick_count == played_tracks_count)
    {
        for (int j = 0; j < draft_count; j++)
        {
            draft[j]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #556757; min-width: 80px; color: #949494; font: 22px; font-family: Pacifico;");
            draft[j]->setEnabled(false);
        }
    }
}

void MainWindow::on_fuck_clicked()
{
    pick_count = 0;
    ban_count = 0;


    for (int i = 0; i < played_tracks_count; i++)
    {
        picks[i]->setText("");
    }

    for (int i = 0; i < draft_count; i++)
    {
        draft[i]->setEnabled(true);
        bans[i]->setEnabled(true);
        draft[i]->setStyleSheet("border: 0px solid; border-radius: 15px; background-color: #2A5530; min-width: 80px; color: #FFFFFF; font: 22px; font-family: Pacifico; background-image: url(:/track.png);");
    }
}

void MainWindow::on_pushButton_clicked()
{

}
