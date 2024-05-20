import processing.serial.*;  // Importa la biblioteca para la comunicación serial
import java.nio.ByteBuffer;  // Importa ByteBuffer para manejar los bytes de manera eficiente
import java.nio.ByteOrder;   // Importa ByteOrder para especificar el orden de los bytes

Serial myPort;  // Crea un objeto Serial para gestionar la comunicación serial

// Constantes para especificar las dimensiones y formato de los datos de la imagen
final int cameraWidth = 176;   // Ancho de la imagen capturada por la cámara
final int cameraHeight = 144;  // Alto de la imagen capturada por la cámara
final int cameraBytesPerPixel = 2;  // Bytes por píxel, RGB565 utiliza 2 bytes
final int bytesPerFrame = cameraWidth * cameraHeight * cameraBytesPerPixel;  // Total de bytes por imagen

PImage myImage;  // Imagen donde se mostrarán los datos
byte[] frameBuffer = new byte[bytesPerFrame];  // Buffer para almacenar los datos de un frame completo

void setup() {
  size(320, 240);  // Establece el tamaño de la ventana de la aplicación

  // Inicializa el puerto serial para comunicarse con la cámara
  myPort = new Serial(this, "COM13", 460800);  // Configura el puerto y la velocidad de transmisión

  // Configura el buffer de serial para que espere recibir un frame completo de bytes
  myPort.buffer(bytesPerFrame);  

  // Crea un objeto PImage con el tamaño especificado y formato de color RGB
  myImage = createImage(cameraWidth, cameraHeight, RGB);
}

void draw() {
  image(myImage, 0, 0);  // Dibuja la imagen en la ventana de la aplicación
}

void serialEvent(Serial myPort) {
  // Lee los bytes recibidos por el puerto serial al buffer de frame
  myPort.readBytes(frameBuffer);

  // Prepara el ByteBuffer para manipular los bytes del frame
  ByteBuffer bb = ByteBuffer.wrap(frameBuffer);
  bb.order(ByteOrder.BIG_ENDIAN);  // Especifica que los bytes más significativos vienen primero

  int i = 0;  // Índice para iterar sobre los píxeles de la imagen

  // Mientras haya bytes restantes en el buffer
  while (bb.hasRemaining()) {
    // Lee un píxel en formato RGB565
    short p = bb.getShort();

    // Convierte RGB565 a RGB888 para obtener los valores de color en 8 bits
    int r = ((p >> 11) & 0x1f) << 3;  // Extrae y convierte el componente rojo
    int g = ((p >> 5) & 0x3f) << 2;   // Extrae y convierte el componente verde
    int b = ((p & 0x1f) << 3);        // Extrae y convierte el componente azul

    // Asigna el color al píxel correspondiente en la imagen
    myImage.pixels[i++] = color(r, g, b);
  }
  // Actualiza la imagen con los nuevos píxeles procesados
  myImage.updatePixels();
}
