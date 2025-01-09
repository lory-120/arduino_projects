//codice html della pagina, si modifica in VS code
const String HTMLIndex PROGMEM = R"=====(

<!DOCTYPE html>
<html>
<head>
  <title>Controllo Motore e LED</title>
  <style>
    body {
      text-align: center;
      height: 100vh;
      margin: 0 auto;
    }
    .container {
      text-align: center;
    }
    #motorSlider {
        width: 50%;
    }
  </style>
</head>
<body>
  <h1>Controlli ESP32</h1>
  <div class="container">
    <input type="range" min="0" max="65535" id="motorSlider">
    <p>Valore motore: <span id="sliderValue">0</span></p>
    <label for="led1">LED 1:</label>
    <input type="checkbox" id="led1">
    <label for="led2">LED 2:</label>
    <input type="checkbox" id="led2">
  </div>

  <script>
    const slider = document.getElementById('motorSlider');
    const sliderValue = document.getElementById('sliderValue');
    const led1 = document.getElementById('led1');
    const led2 = document.getElementById('led2');
    const ws = new WebSocket('ws://' + window.location.hostname + ':81');

    ws.onopen = () => {
      console.log('Connessione WebSocket stabilita');
    };

    ws.onmessage = (event) => {
      console.log('Messaggio ricevuto dal server:', event.data);
    };

    function sendData() {
      const data = {
        motorVal: slider.value,
        LED1: led1.checked,
        LED2: led2.checked
      };
      ws.send(JSON.stringify(data));
    }

    slider.addEventListener('input', () => {
      sliderValue.textContent = slider.value;
      sendData();
    });
    led1.addEventListener('change', sendData);
    led2.addEventListener('change', sendData);
  </script>
</body>
</html>

)=====";

const String HTML404 PROGMEM = R"=====(
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