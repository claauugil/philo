# 🍽️ Philosophers

El problema de los Filósofos Comensales es un clásico en sincronización, donde varios filósofos se sientan a una mesa para comer. Cada filósofo necesita dos tenedores para comer, pero hay una cantidad limitada de tenedores disponibles. Esta simulación muestra cómo gestionar la concurrencia usando `pthread` y `mutex` en C, permitiendo que los filósofos compartan recursos de forma segura evitando **deadlocks** y **inanición**.

---

## 🎯 Objetivo

Implementar una solución al problema de los Filósofos Comensales. Los filósofos alternan entre comer 🍴 y dormir 💤, intentando tomar dos tenedores al mismo tiempo. La simulación asegura que ningún filósofo muera por inanición y que los recursos se gestionen eficientemente.

---

## ⚙️ Características

- Cada filósofo es representado como un hilo (`thread`).
- Se usan mutex para evitar condiciones de carrera al acceder a recursos compartidos (tenedores 🍽️, impresión en consola, etc.).
- Un hilo monitor supervisa la simulación, detectando si algún filósofo ha muerto ☠️.

---

## 📝 Notas Importantes

- Los valores de tiempo deben ser al menos **60 ms** ⏳.
- No se permiten valores negativos ni entradas no numéricas.
- Si solo hay un filósofo, este cogerá un tenedor y eventualmente morirá por inanición (limitación del problema).

---

## 🔢 Argumentos del Programa

| Argumento                            | Descripción                                                                 |
|--------------------------------------|-----------------------------------------------------------------------------|
| `number_of_philosophers`             | Número de filósofos (y tenedores 🍴) en la mesa.                           |
| `time_to_die`                        | Tiempo en milisegundos ⏱️ que un filósofo puede vivir sin comer.           |
| `time_to_eat`                        | Tiempo en milisegundos ⏱️ que tarda un filósofo en comer.                  |
| `time_to_sleep`                      | Tiempo en milisegundos ⏱️ que tarda un filósofo en dormir.                 |
| `[number_of_times_each_philosopher_must_eat]` (opcional) | Si se especifica, la simulación termina cuando todos los filósofos hayan comido al menos esta cantidad de veces 🍽️. |

---

## 🚀 Ejecución

```bash
./philosophers number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat
```

## 🧪 Ejemplos de Ejecución

Ejemplo 1: Simulación con 5 filósofos sin límite de comidas

```bash
./philosophers 5 800 200 200
```
