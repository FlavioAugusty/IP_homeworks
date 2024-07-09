import tensorflow as tf
from tensorflow.keras.layers import Dense, Reshape, Flatten, Conv2D, Conv2DTranspose
from tensorflow.keras.models import Sequential
from tensorflow.keras.optimizers import Adam
import numpy as np
import matplotlib.pyplot as plt

# Carregar o conjunto de dados CIFAR-10
(train_images, _), (_, _) = tf.keras.datasets.cifar10.load_data()
train_images = (train_images - 127.5) / 127.5  # Normalização das imagens para o intervalo [-1, 1]

# Construir o gerador
generator = Sequential([
    Dense(4 * 4 * 256, input_dim=100, activation='relu'),
    Reshape((4, 4, 256)),
    Conv2DTranspose(128, kernel_size=3, strides=2, padding='same', activation='relu'),
    Conv2DTranspose(64, kernel_size=3, strides=2, padding='same', activation='relu'),
    Conv2DTranspose(3, kernel_size=3, strides=2, padding='same', activation='tanh')
])

# Construir o discriminador
discriminator = Sequential([
    Conv2D(64, kernel_size=3, strides=2, padding='same', activation='relu', input_shape=(32, 32, 3)),
    Conv2D(128, kernel_size=3, strides=2, padding='same', activation='relu'),
    Conv2D(256, kernel_size=3, strides=2, padding='same', activation='relu'),
    Flatten(),
    Dense(1, activation='sigmoid')
])

# Compilar o discriminador
discriminator.compile(loss='binary_crossentropy', optimizer=Adam(learning_rate=0.0002, beta_1=0.5), metrics=['accuracy'])

# Congelar o discriminador durante o treinamento do gerador
discriminator.trainable = False

# Construir e compilar a GAN
gan = Sequential([generator, discriminator])
gan.compile(loss='binary_crossentropy', optimizer=Adam(learning_rate=0.0002, beta_1=0.5))

# Função para gerar amostras de ruído aleatório
def generate_noise(samples, noise_dim):
    return np.random.normal(0, 1, (samples, noise_dim))

# Função para treinar a GAN
def train_gan(epochs, batch_size, noise_dim):
    for epoch in range(epochs):
        # Treinamento do discriminador
        real_images = train_images[np.random.randint(0, train_images.shape[0], batch_size)]
        real_labels = np.ones((batch_size, 1))
        fake_images = generator.predict(generate_noise(batch_size, noise_dim))
        fake_labels = np.zeros((batch_size, 1))
        
        discriminator_loss_real = discriminator.train_on_batch(real_images, real_labels)
        discriminator_loss_fake = discriminator.train_on_batch(fake_images, fake_labels)
        discriminator_loss = 0.5 * np.add(discriminator_loss_real, discriminator_loss_fake)
        
        # Treinamento do gerador
        noise = generate_noise(batch_size, noise_dim)
        generator_loss = gan.train_on_batch(noise, np.ones((batch_size, 1)))
        
        # Exibir progresso a cada 100 épocas
        if epoch % 100 == 0:
            print(f'Epoch {epoch}, Discriminator Loss: {discriminator_loss[0]}, Generator Loss: {generator_loss}')
            # Gerar e exibir uma imagem gerada pelo gerador
            generated_image = generator.predict(generate_noise(1, noise_dim))
            plt.imshow(generated_image[0])
            plt.axis('off')
            plt.show()

# Parâmetros de treinamento
epochs = 2000
batch_size = 32
noise_dim = 100

# Treinar a GAN
train_gan(epochs, batch_size, noise_dim)
