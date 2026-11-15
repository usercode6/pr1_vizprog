// Подключаем описание главного окна, UI и используемые виджеты Qt
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QSlider>
#include <QStyle>
#include <QToolButton>

// Инициализируем базовый класс окна и создаём объект Ui::MainWindow
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(std::make_unique<Ui::MainWindow>())
{
    // Задаём заголовок и начальный размер окна
    setWindowTitle("Медиапроигрыватель");
    resize(900, 650);

    // Создаём меню «Медиа» и его действия
    QMenu* mediaMenu = menuBar()->addMenu("Медиа");
    mediaMenu->addAction("Открыть папку");
    mediaMenu->addAction("Открыть файл");

    // Создаём меню «Воспроизвести» и его действия
    QMenu* reproduceMenu = menuBar()->addMenu("Воспроизвести");
    reproduceMenu->addAction("Открыть папку");
    reproduceMenu->addAction("Открыть файл");

    // Создаём меню управления звуком
    QMenu* audioMenu = menuBar()->addMenu("Аудио");
    audioMenu->addAction("Увеличить громкость");
    audioMenu->addAction("Уменьшить громкость");

    // Создаём меню управления видео
    QMenu* videoMenu = menuBar()->addMenu("Видео");
    videoMenu->addAction("Полноэкранный режим");
    videoMenu->addAction("Сделать снимок кадра");

    // Создаём меню управления субтитрами
    QMenu* subtitlesMenu = menuBar()->addMenu("Субтитры");
    subtitlesMenu->addAction("Включить субтитры");
    subtitlesMenu->addAction("Отключить субтитры");

    // Создаём меню инструментов
    QMenu* intstrumentsMenu = menuBar()->addMenu("Инструменты");
    intstrumentsMenu->addAction("Настройки");
    intstrumentsMenu->addAction("Информация о медиа");

    // Создаём меню настройки вида
    QMenu* viewMenu = menuBar()->addMenu("Вид");
    viewMenu->addAction("Показать плейлист");

    // Создаём меню справки
    QMenu* helpMenu = menuBar()->addMenu("Помощь");
    helpMenu->addAction("О программе...");

    // Создаём центральный виджет и передаём его главному окну
    QWidget* central = new QWidget(this);
    setCentralWidget(central);

    // Устанавливаем вертикальную компоновку для центрального виджета
    // Убираем внешние отступы и промежутки между элементами
    QVBoxLayout* mainLayout = new QVBoxLayout(central);
    mainLayout->setContentsMargins(0, 0, 0, 0);
    mainLayout->setSpacing(0);

    // Создаём чёрную область с изображением по центру
    // Ignored позволяет компоновке изменять её размер независимо от размера картинки
    QLabel* videoLabel = new QLabel(central);
    videoLabel->setStyleSheet("background-color: black;");
    videoLabel->setAlignment(Qt::AlignCenter);
    videoLabel->setSizePolicy(QSizePolicy::Ignored,QSizePolicy::Ignored);

    // Загружаем изображение конуса по пути относительно рабочей папки приложения
    QPixmap conus("../../../pr1_part1/images/conus.png");

    // Устанавливаем изображение в метку
    videoLabel->setPixmap(conus);

    // Добавляем область изображения с коэффициентом растяжения 1
    mainLayout->addWidget(videoLabel,1);

    // Создаём нижнюю панель с вертикальной компоновкой
    // Задаём отступы слева, сверху, справа, снизу и промежуток между строками
    QWidget* panel = new QWidget(central);
    QVBoxLayout* panelLayout = new QVBoxLayout(panel);
    panelLayout->setContentsMargins(10, 6, 10, 8);
    panelLayout->setSpacing(8);

    // Размещаем нижнюю панель под областью изображения
    mainLayout->addWidget(panel);

    // Создаём горизонтальную компоновку строки перемотки
    QHBoxLayout* seekLayout = new QHBoxLayout;

    // Создаём метки текущего времени и общей длительности
    QLabel* currentTime = new QLabel("00:00", panel);
    QLabel* totalTime = new QLabel("00:00", panel);

    // Создаём ползунок перемотки с диапазоном от 0 до 100
    QSlider* seekSlider = new QSlider(Qt::Horizontal, panel);
    seekSlider->setRange(0, 100);
    seekSlider->setValue(0);

    // Размещаем ползунок между метками времени и разрешаем ему растягиваться
    seekLayout->addWidget(currentTime);
    seekLayout->addWidget(seekSlider, 1);
    seekLayout->addWidget(totalTime);

    // Добавляем строку перемотки в нижнюю панель
    panelLayout->addLayout(seekLayout);

    // Создаём горизонтальную строку кнопок и регулятора громкости
    QHBoxLayout* controlsLayout = new QHBoxLayout;
    controlsLayout->setSpacing(6);

    // Создаём четыре группы кнопок
    // Для второй, третьей и четвёртой групп задаём левый отступ 15
    QHBoxLayout* specialLayout_1 = new QHBoxLayout;
    specialLayout_1->setContentsMargins(0,0, 0, 0);
    QHBoxLayout* specialLayout_2 = new QHBoxLayout;
    specialLayout_2->setContentsMargins(15,0, 0, 0);
    QHBoxLayout* specialLayout_3 = new QHBoxLayout;
    specialLayout_3->setContentsMargins(15 ,0, 0, 0);
    QHBoxLayout* specialLayout_4 = new QHBoxLayout;
    specialLayout_4->setContentsMargins(15,0, 0, 0);

    // создаём кнопку со стандартной иконкой или иконкой из файла
    // tooltip задаёт подсказку, id определяет группу кнопки
    auto addButton = [&](std::variant<QStyle::StandardPixmap, QString> icon, const QString &tooltip, uint8_t id)
    {
        // Создаём кнопку на нижней панели
        QToolButton* button = new QToolButton(panel);

        // Проверяем, содержит ли variant стандартную иконку Qt
        if (const auto* standard = std::get_if<QStyle::StandardPixmap>(&icon))
        {
            button->setIcon(style()->standardIcon(*standard));
        }
        else
        {
            // Получаем путь из variant и загружаем иконку из файла
            const QString& path = std::get<QString>(icon);
            button->setIcon(QIcon(path));
        }

        // Настраиваем размер иконки, размер кнопки и всплывающую подсказку
        button->setIconSize(QSize(18, 18));
        button->setFixedSize(32, 28);
        button->setToolTip(tooltip);

        // Выбираем группу по id и добавляем в неё кнопку
        if (id==1)
        {
            specialLayout_1->addWidget(button);
            controlsLayout->addLayout(specialLayout_1);
        }
        else if (id==2)
        {
            specialLayout_2->addWidget(button);
            controlsLayout->addLayout(specialLayout_2);
        }
        else if (id==3)
        {
            specialLayout_3->addWidget(button);
            controlsLayout->addLayout(specialLayout_3);
        }
        else
        {
            specialLayout_4->addWidget(button);
            controlsLayout->addLayout(specialLayout_4);
        }

        // Возвращаем указатель на созданную кнопку
        return button;
    };

    // Создаём кнопки воспроизведения со стандартными иконками Qt
    addButton(QStyle::SP_MediaPlay,"Воспроизвести",1);
    addButton(QStyle::SP_MediaSeekBackward,"Назад",2);
    addButton(QStyle::SP_MediaStop,"Остановить",2);
    addButton(QStyle::SP_MediaSeekForward,"Вперёд",2);

    // Создаём дополнительные кнопки с иконками из файлов
    addButton("../../../pr1_part1/images/rastyanut.png","Растянуть окно",3);
    addButton("../../../pr1_part1/images/ecvalaizer.png","Эквалайзер",3);
    addButton("../../../pr1_part1/images/list.png","Плейлист",4);
    addButton("../../../pr1_part1/images/repeat.png", "Повтор",4);
    addButton("../../../pr1_part1/images/shuffle.png","Перемешать",4);

    // Добавляем растягиваемый промежуток, отодвигающий громкость вправо
    controlsLayout->addStretch(1);

    // Создаём ползунок громкости с начальным значением 50 и шириной 100
    QSlider* volumeSlider = new QSlider(Qt::Horizontal, panel);
    volumeSlider->setRange(0,100);
    volumeSlider->setValue(50);
    volumeSlider->setFixedWidth(100);

    // Создаём текстовый индикатор громкости
    QLabel* volumeText = new QLabel("50%", panel);
    volumeText->setMinimumWidth(40);

    // Создаём метку с картинкой громкости
    // Масштабируем картинку с сохранением пропорций и плавным преобразованием
    auto *volumeImage = new QLabel(panel);
    volumeImage->setFixedSize(70, 20);
    volumeImage->setAlignment(Qt::AlignCenter);
    volumeImage->setPixmap(QPixmap("../../../pr1_part1/images/Photoroom.png").scaled(70, 20,Qt::KeepAspectRatio,Qt::SmoothTransformation));

    // Добавляем ползунок, процент и картинку в строку управления
    controlsLayout->addWidget(volumeSlider);
    controlsLayout->addWidget(volumeText);
    controlsLayout->addWidget(volumeImage);

    // Добавляем строку управления в нижнюю панель
    panelLayout->addLayout(controlsLayout);

    // При изменении значения ползунка обновляем надпись с процентом громкости
    connect(volumeSlider, &QSlider::valueChanged,
            volumeText, [volumeText](int value)
            {
                volumeText->setText(QString::number(value) + "%");
            });

}

// Используем стандартный деструктор: unique_ptr освобождает ui,
// а дочерние объекты Qt удаляются через механизм родительского владения
MainWindow::~MainWindow()  = default;