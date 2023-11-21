#include <EloquentTinyML.h>
#include <eloquent_tinyml/tensorflow.h>

#include "model.h"

#define NUMBER_OF_INPUTS 2
#define NUMBER_OF_OUTPUTS 1
#define TENSOR_ARENA_SIZE 2*1024

Eloquent::TinyML::TensorFlow::TensorFlow<NUMBER_OF_INPUTS, NUMBER_OF_OUTPUTS, TENSOR_ARENA_SIZE> tf; //comment it if you're using 0.0.5 version

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Start Model");
  tf.begin(model_data);
}

void loop() {
  // put your main code here, to run repeatedly:
  float x1 = random(20, 40);
  float x2 = random(30, 100);
  Serial.println("Reading...");
  delay(2000);

  float input[2] = {x1, x2};
  float klasifikasi = tf.predict(input);

  Serial.println("Suhu X1 = " + String(x1));
  Serial.println("Kelembaban X2 = " + String(x2));
  Serial.println("Klasifikasi = " + String(klasifikasi) + " : ");
  if (klasifikasi > 0.5)
  {
    Serial.println("Nyaman");
  }
  else
  {
    Serial.println("Tidak Nyaman");
  }
}
