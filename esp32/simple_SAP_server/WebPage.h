//modifica tutto in VS code
//String INSERISCI-NOME PROGMEM = R"=====()=====";

//questo è l'inizio dell'HTML, dove ci sta l'header con gli stili

String HTMLIndex PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Controlli ESP32</title>
    <style>
        body {
            font-family: Arial, sans-serif;
            margin: 0;
            padding: 20px;
            min-height: 100vh;
            background: 
                linear-gradient(45deg, #ff5c00, #84d000, #00a5e1);
                background-blend-mode: overlay;
            background-size: 400% 400%, 100% 100%;
            animation: gradient 15s ease infinite, marmorize 10s ease-in-out infinite alternate;
        }

        @keyframes gradient {
            0% { background-position: 0% 50%, 0 0; }
            50% { background-position: 100% 50%, 0 0; }
            100% { background-position: 0% 50%, 0 0; }
        }

        @keyframes marmorize {
            0% { backdrop-filter: hue-rotate(0deg) blur(5px); }
            100% { backdrop-filter: hue-rotate(90deg) blur(10px); }
        }

        .glass-panel {
            background-color: rgba(255, 255, 255, 0.1);
            backdrop-filter: blur(10px);
            border-radius: 15px;
            padding: 20px;
            width: 90%;
            max-width: 400px;
            box-shadow: 0 4px 6px rgba(0, 0, 0, 0.1);
            margin: 20px auto;
        }

        h1 {
            text-align: center;
            margin-bottom: 20px;
            font-size: 2.5em;
            background: linear-gradient(45deg, #ffffff7f, #f5f5dcb1, #f0ffff94);
            background-size: 200% 200%;
            animation: gradientBG 5s ease infinite;
            -webkit-background-clip: text;
            background-clip: text;
            color: #32729f;
            padding: 10px;
            border-radius: 10px;
            position: relative;
        }

        h1::before {
            content: "";
            position: absolute;
            top: 0;
            right: 0;
            bottom: 0;
            left: 0;
            background: linear-gradient(45deg, #ffffff7f, #f5f5dcb1, #f0ffff94);
            background-size: 200% 200%;
            animation: gradientBG 5s ease infinite;
            opacity: 0.7;
            border-radius: 10px;
            z-index: -1;
        }
        h2 {
            font-size: 1.8em;
            text-align: center;
            font-weight: bolder;
            color: #0080dc;
        }
        h3 {
            font-size: 1.4em;
            font-weight: bolder;
            margin-bottom: 13%;
        }

        @keyframes gradientBG {
            0% { background-position: 0% 50%; }
            50% { background-position: 100% 50%; }
            100% { background-position: 0% 50%; }
        }

        .tile {
            background-color: rgba(255, 255, 255, 0.1);
            border-radius: 10px;
            padding: 15px;
            margin-bottom: 20px;
        }

        .led-switches {
            display: flex;
            justify-content: space-around;
        }

        .switch {
            position: relative;
            display: inline-block;
            width: 60px;
            height: 34px;
            transform: translate(0%, 20%);            
        }

        .led {
            text-align: center;
            display: flex;
            flex-direction: column;
            justify-content: center;
            transform: translate(0%, -20%);
        }
        #red {
            color: rgb(255, 56, 56);
        }
        #green {
            color: #00aa00;
        }
        #blue {
            color: #006aff;
        }

        .switch input {
            opacity: 0;
            width: 0;
            height: 0;
        }

        .slider {
            position: absolute;
            cursor: pointer;
            top: 0;
            left: 0;
            right: 0;
            bottom: 0;
            background-color: #ccc;
            transition: .4s;
            border-radius: 34px;
        }

        .slider:before {
            position: absolute;
            content: "";
            height: 26px;
            width: 26px;
            left: 4px;
            bottom: 4px;
            background-color: white;
            transition: .4s;
            border-radius: 50%;
        }

        input:checked + .slider {
            background-color: #2196F3;
        }

        input:checked + .slider:before {
            transform: translateX(26px);
        }

        .progress-bar {
            width: 80%;
            height: 30px;
            margin: 20px auto;
            position: relative;
            background-color: #444;
            border-radius: 10px;
            overflow: hidden;
            border-style: solid;
            border-width: 1%;
            border-color: #983800;
        }

        .progress-fill {
            height: 100%;
            background-color: #e28400;
            width: 0%;
            transition: width 0.3s ease-in-out;
        }

        .progress-value {
            position: absolute;
            top: 50%;
            left: 50%;
            transform: translate(-50%, -50%);
            font-size: 14px;
            font-weight: bold;
            color: #fff;
        }

        .motor-control {
            width: 100%;
        }

        .motor-slider {
            width: 100%;
            -webkit-appearance: none;
            appearance: none;
            height: 15px;
            border-radius: 5px;
            background: #444;
            outline: none;
            opacity: 0.7;
            transition: opacity .2s;
        }

        .motor-slider:hover {
            opacity: 1;
        }

        .motor-slider::-webkit-slider-thumb {
            -webkit-appearance: none;
            appearance: none;
            width: 25px;
            height: 25px;
            border-radius: 50%;
            background: #2196F3;
            cursor: pointer;
        }

        .motor-slider::-moz-range-thumb {
            width: 25px;
            height: 25px;
            border-radius: 50%;
            background: #2196F3;
            cursor: pointer;
        }

        .motor-value {
            text-align: center;
            font-size: 18px;
            margin-top: 10px;
        }

        .reset-button {
            display: block;
            width: 100%;
            padding: 10px;
            margin-top: 10px;
            background-color: #2196F3;
            color: white;
            border: none;
            border-radius: 5px;
            font-size: 16px;
            cursor: pointer;
            transition: background-color 0.3s;
        }

        .reset-button:hover {
            background-color: #0d8aee;
        }
    </style>
</head>
<body>
    <div class="glass-panel">
        <h1>Pannello di controllo ESP32</h1>
        
        <div class="tile">
            <h2>LED</h2>
            <div class="led-switches">
                <div class="led">
                    <h3 id="red">Rosso</h3>
                    <label class="switch">
                        <input type="checkbox" id="redSwitch">
                        <span class="slider"></span>
                    </label>
                </div>
                <div class="led"> 
                    <h3 id="green">Verde</h3>
                    <label class="switch">
                        <input type="checkbox" id="greenSwitch">
                        <span class="slider"></span>
                    </label>
                </div>
                <div class="led">
                    <h3 id="blue">Blu</h3>
                    <label class="switch">
                        <input type="checkbox" id="blueSwitch">
                        <span class="slider"></span>
                    </label>
                </div>
            </div>
        </div>
        
        <div class="tile">
            <h2>Potenziometro</h2>
            <div class="progress-bar">
                <div class="progress-fill" id="progressFill"></div>
                <div class="progress-value" id="progressValue">0</div>
            </div>
        </div>
        
        <div class="tile">
            <h2>Controllo motore</h2>
            <div class="motor-control">
                <!--MODIFICA QUI IL RANGE MIN E MAX-->
                <input type="range" min="-255" max="255" value="0" class="motor-slider" id="motorSlider">
                <div class="motor-value" id="motorValue">0</div>
                <button class="reset-button" id="resetButton">Reset</button>
            </div>
        </div>
    </div>

    <script>
        //oggetti e variabili dei LED
        const redSwitch = document.getElementById('redSwitch');
        const greenSwitch = document.getElementById('greenSwitch');
        const blueSwitch = document.getElementById('blueSwitch');
        var redVal = false, greenVal = false, blueVal = false; //stati iniziali dei led

        //oggetti e variabili della barra del potenziometro
        const progressFill = document.getElementById('progressFill');
        const progressValue = document.getElementById('progressValue');
        let potValue = -1; //valore iniziale di test
        const maxPotValue = 4095; //valore massimo del potenziometro

        //oggetti e variabili dei motori
        const motorSlider = document.getElementById('motorSlider');
        const resetButton = document.getElementById('resetButton');
        const motorValue = document.getElementById('motorValue');
        var motorSpinValue = 0; //valore iniziale del motore

        //connessione WebSocket
        const socket = new WebSocket('ws://' + window.location.hostname + ':81');

        //gestione dei vari eventi del WS
        socket.addEventListener('error', (error) => {
            console.error('Errore WebSocket:', error);
        });
        socket.addEventListener('close', () => {
            console.log('Connessione WebSocket chiusa');
        });



        //messaggio da inviare al server
        var message = {
            RState: redVal,
            GState: greenVal,
            BState: blueVal,
            motorVal: motorSpinValue
        };



        //funzione per inviare il messaggio WebSocket con debouncing
        //la più importante, è quella che manda i messaggi
        let debounceTimeout;
        function debounceSendMessage() {
            clearTimeout(debounceTimeout);
            debounceTimeout = setTimeout(() => {
                const JSONString = JSON.stringify(message);
                socket.send(JSONString);
                //console.log("Messaggio inviato:", JSONString);      /////(per debuggare lol)
            }, 50);
        }



        /*listener per i led: se "senti" un cambiamento, richiama la funzione
        updateSwitchState() con parametro il colore*/
        redSwitch.addEventListener('change', () => {
            redVal = redSwitch.checked;
            message.RState = redVal;
            debounceSendMessage();
        });
        greenSwitch.addEventListener('change', () => {
            greenVal = greenSwitch.checked;
            message.GState = greenVal;
            debounceSendMessage();
        });
        blueSwitch.addEventListener('change', () => {
            blueVal = blueSwitch.checked;
            message.BState = blueVal;
            debounceSendMessage();
        });
        /*AGGIUNGERE IL LISTENER PER INVIARE GLI STATI DEI LED QUA*/



        //funzione per aggiornare la barra del potenziometro
        function updateProgressBar(value) {
            const percentage = (value / maxPotValue) * 100;
            progressFill.style.width = percentage + '%';
            progressValue.textContent = value;
        }

        //evento che rileva nuovi dati in ricezione dal WS (quindi solo il potenziometro)
        socket.addEventListener('message', (event) => {
            console.log("Messaggio ricevuto:", event.data); //(per debuggare lol)

            const data = JSON.parse(event.data);
            //!== è DISUGUAGLIANZA STRETTA
            if (data.potValue !== undefined) { //"se il dato del potenz. NON E' definito, fai..."
                potValue = data.potValue;

            } else {
                potValue = -1;
            }
            updateProgressBar(potValue);
        });



        //event listener per il slider del motore
        motorSlider.addEventListener('input', () => {
            motorSpinValue = parseInt(motorSlider.value); // Assicurati di convertire in intero
            motorValue.textContent = motorSpinValue;
            message.motorVal = motorSpinValue; // Aggiorna il valore nel messaggio
            debounceSendMessage();
        });

        //event listener per il pulsante di reset
        resetButton.addEventListener('click', () => {
            motorSlider.value = 0;
            motorValue.textContent = 0;
            motorSpinValue = 0;
            message.motorVal = 0; // Aggiorna il valore nel messaggio
            debounceSendMessage();
        });

    </script>
</body>
</html>
)=====";

/*=========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
===========================================================================================
*/

String HTML404 PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="it">
    <head>
        <meta charset="UTF-8">
        <meta name="viewport" content="width=device-width, initial-scale=1.0">
        <title>ESP32: 404 Not Found</title>
        <style>

            body {
                max-width: fit-content;
                margin-inline: auto;
                margin: 0 auto;
                text-align: center;
                background-color: #202020;
                font-family: Arial, Helvetica, sans-serif;
            }
            h1 {
                color: white;
                font-size: 3em;
            }
        </style>
    </head>

    <body>
      <h1>Pagina non trovata :(</h1>
    </body>
</html>
)=====";