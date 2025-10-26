import QtQuick
import QtQuick.Controls
import QmlExtension 1.0

ApplicationWindow {
    id: window
    width: 640
    height: 480
    visible: true
    title: "Suav Casino Plugin"

    property var deck: []
    property var dealerHand: []
    property var playerHand: []
    property bool revealDealer: false
    property int money: 1000
    property bool gameInProgress: false

    function drawCard() {
        const card = deck.pop()
        return card
    }

    function getHandValue(hand) {
        var value = 0
        var aces = 0
        for (let c of hand) {
            if (c.rank === "A") {
                value += 11
                aces++
            } else if (["J", "Q", "K"].includes(c.rank)) {
                value += 10
            } else {
                value += parseInt(c.rank)
            }
        }
        while (value > 21 && aces > 0) {
            value -= 10
            aces--
        }
        return value
    }

    function newDeck() {
        let suits = ["♠", "♥", "♦", "♣"]
        let ranks = ["A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K"]
        let d = []
        for (let s of suits)
            for (let r of ranks)
                d.push({rank: r, suit: s})
        for (let i = d.length - 1; i > 0; i--) {
            let j = Math.floor(Math.random() * (i + 1))
            let temp = d[i]
            d[i] = d[j]
            d[j] = temp
        }
        return d
    }

    function startGame() {
        gameInProgress = true
        deck = newDeck()
        dealerHand = [drawCard(), drawCard()]
        playerHand = [drawCard(), drawCard()]
        revealDealer = false
        updateLabels()
        resultLabel.text = ""
    }

    function updateLabels() {
        if (revealDealer) {
            dealerLabel.text = "Dealer: " + dealerHand.map(c => c.rank + c.suit).join(" ")
        } else if (dealerHand.length > 0) {
            dealerLabel.text = "Dealer: " + dealerHand[0].rank + dealerHand[0].suit + " [Hidden]"
        } else {
            dealerLabel.text = "Dealer: "
        }
        playerLabel.text = "Player: " + playerHand.map(c => c.rank + c.suit).join(" ")
    }

    function hit() {
        playerHand.push(drawCard())
        updateLabels()
        if (getHandValue(playerHand) > 21) {
            resultLabel.text = "Bust! Dealer wins."
            revealDealer = true
            updateLabels()
            money -= betValue.value
            gameInProgress = false
        }
    }

    function stand() {
        revealDealer = true
        while (getHandValue(dealerHand) < 17)
            dealerHand.push(drawCard())

        let playerValue = getHandValue(playerHand)
        let dealerValue = getHandValue(dealerHand)

        updateLabels()

        if (dealerValue > 21 || playerValue > dealerValue) {
            resultLabel.text = "You win!"
            money += betValue.value
        }
        else if (dealerValue === playerValue) {
            resultLabel.text = "Push (tie)."
        }
        else {
            resultLabel.text = "Dealer wins."
            money -= betValue.value
        }
        gameInProgress = false
    
    }

    Column {
        anchors.centerIn: parent
        spacing: 12

        Label {
            id: titleId

            text: vehicle ? "While waiting for " + vehicle.vehicleId + " play some blackjack" : "no vehicle"
            font.pixelSize: 18
        }

        Label {
            id: dealerLabel

            text: "Dealer: " + dealerHand.map(c => c.rank + c.suit).join(" ")
            font.pixelSize: 18
        }

        Label {
            id: playerLabel

            text: "Player: " + playerHand.map(c => c.rank + c.suit).join(" ")
            font.pixelSize: 18
        }

        Row {
            spacing: 10
            Button {
                text: "New Game"
                onClicked: { startGame(); } 
                enabled: money > 0 && betValue.value > 0 && !gameInProgress
            }

            Button { 
                text: "Hit" 
                onClicked: { hit(); }
                enabled: resultLabel.text === "" && gameInProgress
            }

            Button { 
                text: "Stand"
                onClicked: { stand(); }
                enabled: resultLabel.text === "" && gameInProgress
            }
            Label {
                id: balanceLabel
                text: "Current Balance " + money + "$"
                horizontalAlignment: Text.AlignHCenter
            }
            SpinBox {
                id: betValue

                enabled: !gameInProgress
                value: 100
                editable: true
                from: 0
                to: 1000000
            }
        }
        Label {
            id: outOfMoneyLabel

            text: "Get a job and make more money pal"
            visible: money <= 0
        }


        Label {
            id: resultLabel
            text: ""
            font.pixelSize: 20
            color: "gold"
            horizontalAlignment: Text.AlignHCenter
        }
    }
}
