#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(Commande* commande, Filtre* filtre, Menu* menu, QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow),
    commande_(commande), filtre_(filtre), menu_(menu)
{
    ui->setupUi(this);
    setUI();
    connecterSignauxAuxSlots();
    mettreAJourPlatsFiltres();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setUI(){
    setWindowTitle(WINDOW_TITLE);
    creerWidgets();
    designLayout();
}

void MainWindow::creerWidgets(){
    creerWidgetTypeMenu();
    creerWidgetConditionsAlimentaires();
    creerWidgetPlatsFiltres();
    creerWidgetCommande();
    creerWidgetBoutonsAjouterRetirer();
    creerWidgetPrix();
    creerWidgetCommander();
}

void MainWindow::creerWidgetTypeMenu() {
    widgetTypeMenu_ = new QComboBox(this);
    widgetTypeMenu_->addItem(MATIN);
    widgetTypeMenu_->addItem(MIDI);
    widgetTypeMenu_->addItem(SOIR);
}

void MainWindow::creerWidgetConditionsAlimentaires(){
    widgetPlatsBios_ =  new QCheckBox(BIOLOGIQUE,this);
    widgetPlatsVeges_ = new QCheckBox(VEGETARIEN, this);
}

void MainWindow::creerWidgetPlatsFiltres(){
    widgetPlatsFiltres_ = new QListWidget(this);
    widgetPlatsFiltres_->setSortingEnabled(true);
}

//TODO done
void MainWindow::creerWidgetCommande() {
    widgetCommande_ = new QListWidget(this);
    widgetCommande_->setSortingEnabled(true);
}

void MainWindow::creerWidgetBoutonsAjouterRetirer() {
    widgetAjouterPlat_ = new QPushButton(this);
    widgetAjouterPlat_->setText(AJOUTER_PLAT);
    widgetRetirerPlat_ = new QPushButton(this);
    widgetRetirerPlat_->setText(RETIRER_PLAT);
}

void MainWindow::creerWidgetPrix() {
    widgetPrix_ = new QLabel(this);
    widgetPrix_->setText(PRIX_STRING + "0" + DOLLAR_SIGN);
}

//TODO done
void MainWindow::creerWidgetCommander() {
    widgetCommander_ = new QPushButton(this);
    widgetCommander_->setText(COMMANDER);
}



//TODO done
void MainWindow::designLayout() {

    QFrame* hLine = new QFrame();
    hLine->setFrameShape(QFrame::HLine);

    QVBoxLayout* mainBox = new QVBoxLayout(this);

    QWidget* mainWidget = new QWidget();
    mainWidget->setLayout(mainBox);
    setCentralWidget(mainWidget);



    QHBoxLayout* box1 = new QHBoxLayout;
    QVBoxLayout* box2 = new QVBoxLayout;
    QVBoxLayout* box3 = new QVBoxLayout;
    QHBoxLayout* box4 = new QHBoxLayout;


    box2->addWidget(widgetTypeMenu_);
    box2->addWidget(widgetPlatsBios_);
    box2->addWidget(widgetPlatsVeges_);

    box3->addWidget(widgetPlatsFiltres_);
    box4->addWidget(widgetAjouterPlat_);
    box4->addWidget(widgetRetirerPlat_);
    box3->addLayout(box4);

    box1->addLayout(box2);
    box1->addLayout(box3);

    mainBox->addLayout(box1);
    mainBox->addWidget(hLine);

   QVBoxLayout* box5 = new QVBoxLayout;
   QHBoxLayout* box6 = new QHBoxLayout;

   box5->addWidget(widgetCommande_);

   box6->addWidget(widgetPrix_);
   box6->addWidget(widgetCommander_);

   box5->addLayout(box6);

   mainBox->addLayout(box5);


}

/*
 * Connecte les actions de l'utilisateur sur l'interface aux modifications qui
 * doivent être faites sur le modèle
*/
void MainWindow::connecterSignauxAuxSlots() {
    // connecter checkboxes filtre bio et vege
    QObject::connect(widgetPlatsVeges_, SIGNAL(stateChanged(int)),
                     this, SLOT(clicOptionVege()));
    QObject::connect(widgetPlatsBios_, SIGNAL(stateChanged(int)),
                     this, SLOT(clicOptionBio()));

    //connecter menu defilant type plat
    QObject::connect(widgetTypeMenu_, SIGNAL(currentIndexChanged(QString)),
                     this, SLOT(choixTypeMenu(QString)));

    //TODO done
    //connecter boutons ajouterPlat et retirerPlat
    QObject::connect(widgetAjouterPlat_, SIGNAL(clicked()),
                     this, SLOT(insererPlatsChoisisDansCommande()));
    QObject::connect(widgetRetirerPlat_, SIGNAL(clicked()),
                     this, SLOT(retirerPlatsChoisisDeCommande()));

    //connecter bouton commander
    QObject::connect(widgetCommander_, SIGNAL(clicked()),
                     this, SLOT(commander()));
}






void MainWindow::mettreAJourPlatsFiltres(){
    QStringList plats = filtre_->getNomPlatsFiltres();
    widgetPlatsFiltres_->clear();
    widgetPlatsFiltres_->addItems(plats);
}

void MainWindow::clicOptionBio(){
    filtre_->clicOptionBio();
}

void MainWindow::clicOptionVege(){
    filtre_->clicOptionVege();
}

void MainWindow::choixTypeMenu(QString typeMenu){
    filtre_->choixTypeMenu(qstringToTypeMenu(typeMenu));
}

void MainWindow::mettreAJourPlatsCommande(){
    widgetCommande_->clear();
    foreach (auto nomPlat, commande_->getCommande()) {
        widgetCommande_->addItem(nomPlat);
    }
}

//TODO done
void MainWindow::insererPlatsChoisisDansCommande() {
    commande_->ajouterPlat(widgetPlatsFiltres_->currentItem()->text());
    mettreAJourPlatsCommande();
    mettreAJourPrix();
}

//TODO gestion erreur done
void MainWindow::retirerPlatsChoisisDeCommande() {
    try {
        commande_->retirerPlat(widgetPlatsFiltres_->currentItem()->text());
    } catch (ErreurPlatIntrouvable erreur) {
        message(erreur.what());
    }
}

void MainWindow::mettreAJourPrix() {

    widgetPrix_->setText(PRIX_STRING +
                         QString::number(calculerPrixCommande()) +
                         DOLLAR_SIGN);
}

int MainWindow::calculerPrixCommande(){
    int prix = 0;
    try {
        foreach(auto nomPlatCommande, commande_->getCommande()){
            prix += menu_->getPlat(nomPlatCommande)->getPrix();
        }
    } catch (ErreurPlatIntrouvable erreur) {
        message(erreur.what());
    }
    return prix;
}

void MainWindow::message(QString erreur) {
    QMessageBox mbox;
    mbox.setText(erreur);
    mbox.exec();
}

void MainWindow::commander() {
    try {
        int prix = calculerPrixCommande();
        commande_->viderCommande();
        message(LABEL_COMMANDE_RECUE+ QString::number(prix) + DOLLAR_SIGN);
    } catch (ErreurCommandeVide erreur) {
        message(erreur.what());
    }
}
