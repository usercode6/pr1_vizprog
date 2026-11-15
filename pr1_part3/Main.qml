import QtQuick
import QtQuick.Window
import QtQuick.Controls
import QtQuick.Layouts
import QtMultimedia

ApplicationWindow {
    id: window

    visible: true

    width: 900
    height: 650

    title: "Медиапроигрыватель"
    font: widgetFont

    color: palette.window

    // Укажи здесь своё видео.
    property url videoSource: "video/video.mp4"

    readonly property bool videoVisible:
        player.playbackState !== MediaPlayer.StoppedState

    function formatTime(milliseconds) {
        let seconds = Math.floor(milliseconds / 1000)
        let minutes = Math.floor(seconds / 60)

        seconds = seconds % 60

        return (minutes < 10 ? "0" : "") + minutes
                + ":"
                + (seconds < 10 ? "0" : "") + seconds
    }

    function togglePlayback() {
        if (player.playbackState === MediaPlayer.PlayingState)
            player.pause()
        else
            player.play()
    }

    function toggleFullscreen() {
        if (window.visibility === Window.FullScreen)
            window.showNormal()
        else
            window.showFullScreen()
    }

    Shortcut {
        sequence: "Escape"

        onActivated: {
            if (window.visibility === Window.FullScreen)
                window.showNormal()
        }
    }

    MediaPlayer {
        id: player

        source: window.videoSource

        videoOutput: videoOutput
        audioOutput: audioOutput

        loops: repeatButton.checked
               ? MediaPlayer.Infinite
               : 1

        onErrorOccurred: function(error, errorString) {
            console.warn("Ошибка видео:", errorString)
        }
    }

    AudioOutput {
        id: audioOutput

        volume: volumeSlider.value / 100
    }

    // Все названия меню и пунктов сохранены из C++.
    menuBar: MenuBar {
        Menu {
            title: "Медиа"

            MenuItem {
                text: "Открыть папку"
            }

            MenuItem {
                text: "Открыть файл"
            }
        }

        Menu {
            title: "Воспроизвести"

            MenuItem {
                text: "Открыть папку"
            }

            MenuItem {
                text: "Открыть файл"
            }
        }

        Menu {
            title: "Аудио"

            MenuItem {
                text: "Увеличить громкость"

                onTriggered: {
                    volumeSlider.value =
                            Math.min(100, volumeSlider.value + 10)
                }
            }

            MenuItem {
                text: "Уменьшить громкость"

                onTriggered: {
                    volumeSlider.value =
                            Math.max(0, volumeSlider.value - 10)
                }
            }
        }

        Menu {
            title: "Видео"

            MenuItem {
                text: "Полноэкранный режим"
                onTriggered: window.toggleFullscreen()
            }

            MenuItem {
                text: "Сделать снимок кадра"
            }
        }

        Menu {
            title: "Субтитры"

            MenuItem {
                text: "Включить субтитры"
            }

            MenuItem {
                text: "Отключить субтитры"
            }
        }

        Menu {
            title: "Инструменты"

            MenuItem {
                text: "Настройки"
            }

            MenuItem {
                text: "Информация о медиа"
            }
        }

        Menu {
            title: "Вид"

            MenuItem {
                text: "Показать плейлист"
            }
        }

        Menu {
            title: "Помощь"

            MenuItem {
                text: "О программе..."
            }
        }
    }

    // Аналог mainLayout:
    // нулевые внешние отступы и расстояние между блоками.
    ColumnLayout {
        anchors.fill: parent
        spacing: 0

        // Аналог videoLabel.
        Rectangle {
            id: videoArea

            Layout.fillWidth: true
            Layout.fillHeight: true
            Layout.minimumHeight: 0

            color: "black"
            clip: true

            VideoOutput {
                id: videoOutput

                anchors.fill: parent
                visible: window.videoVisible

                fillMode: VideoOutput.PreserveAspectFit
            }

            // Без width/height изображение имеет исходный размер,
            // как QPixmap в твоём QLabel.
            Image {
                anchors.centerIn: parent

                source: "images/conus.png"
                visible: !window.videoVisible
            }
        }

        // Аналог panel.
        Rectangle {
            Layout.fillWidth: true
            Layout.preferredHeight: panelLayout.implicitHeight + 14

            color: window.palette.window

            // Аналог panelLayout:
            // слева 10, сверху 6, справа 10, снизу 8.
            ColumnLayout {
                id: panelLayout

                anchors.fill: parent

                anchors.leftMargin: 10
                anchors.topMargin: 6
                anchors.rightMargin: 10
                anchors.bottomMargin: 8

                spacing: 8

                // Первая строка: время — ползунок — время.
                RowLayout {
                    Layout.fillWidth: true

                    spacing: 6

                    Label {
                        text: window.formatTime(player.position)
                    }

                    Slider {
                        id: seekSlider

                        Layout.fillWidth: true
                        Layout.preferredHeight: 20

                        from: 0
                        to: Math.max(1, player.duration)

                        value: player.position

                        onMoved: {
                            if (player.seekable)
                                player.setPosition(Math.round(value))
                        }
                    }

                    Label {
                        text: window.formatTime(player.duration)
                    }
                }

                // Вторая строка: кнопки и громкость.
                RowLayout {
                    Layout.fillWidth: true

                    spacing: 6

                    // Группа 1 — воспроизведение.
                    RowLayout {
                        spacing: 6

                        PlayerButton {
                            imageSource:
                                player.playbackState === MediaPlayer.PlayingState
                                ? "image://standard/pause"
                                : "image://standard/play"

                            tooltipText:
                                player.playbackState === MediaPlayer.PlayingState
                                ? "Пауза"
                                : "Воспроизвести"

                            onClicked: window.togglePlayback()
                        }
                    }

                    // Группа 2 — назад, стоп, вперёд.
                    RowLayout {
                        Layout.leftMargin: 15

                        spacing: 6

                        PlayerButton {
                            imageSource: "image://standard/backward"
                            tooltipText: "Назад"

                            onClicked: {
                                if (player.seekable) {
                                    player.setPosition(
                                        Math.max(0, player.position - 10000)
                                    )
                                }
                            }
                        }

                        PlayerButton {
                            imageSource: "image://standard/stop"
                            tooltipText: "Остановить"

                            onClicked: player.stop()
                        }

                        PlayerButton {
                            imageSource: "image://standard/forward"
                            tooltipText: "Вперёд"

                            onClicked: {
                                if (player.seekable) {
                                    player.setPosition(
                                        Math.min(
                                            player.duration,
                                            player.position + 10000
                                        )
                                    )
                                }
                            }
                        }
                    }

                    // Группа 3 — растянуть окно, эквалайзер.
                    RowLayout {
                        Layout.leftMargin: 15

                        spacing: 6

                        PlayerButton {
                            imageSource: "images/rastyanut.png"
                            tooltipText: "Растянуть окно"

                            onClicked: window.toggleFullscreen()
                        }

                        PlayerButton {
                            imageSource: "images/ecvalaizer.png"
                            tooltipText: "Эквалайзер"
                        }
                    }

                    // Группа 4 — плейлист, повтор, перемешать.
                    RowLayout {
                        Layout.leftMargin: 15

                        spacing: 6

                        PlayerButton {
                            imageSource: "images/list.png"
                            tooltipText: "Плейлист"
                        }

                        PlayerButton {
                            id: repeatButton

                            imageSource: "images/repeat.png"
                            tooltipText: "Повтор"

                            checkable: true
                        }

                        PlayerButton {
                            imageSource: "images/shuffle.png"
                            tooltipText: "Перемешать"
                        }
                    }

                    // Аналог controlsLayout->addStretch(1).
                    Item {
                        Layout.fillWidth: true
                    }

                    Slider {
                        id: volumeSlider

                        Layout.preferredWidth: 100
                        Layout.minimumWidth: 100
                        Layout.maximumWidth: 100
                        Layout.preferredHeight: 20

                        from: 0
                        to: 100

                        stepSize: 1
                        value: 50
                    }

                    Label {
                        Layout.minimumWidth: 40

                        text: Math.round(volumeSlider.value) + "%"
                    }

                    Image {
                        Layout.preferredWidth: 70
                        Layout.minimumWidth: 70
                        Layout.maximumWidth: 70

                        Layout.preferredHeight: 20
                        Layout.minimumHeight: 20
                        Layout.maximumHeight: 20

                        source: "images/Photoroom.png"

                        fillMode: Image.PreserveAspectFit
                        smooth: true
                    }
                }
            }
        }
    }
}