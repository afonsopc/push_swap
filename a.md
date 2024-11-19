1. **Encontre o maior número**:
   - Primeiro, percorra todos os números na pilha para encontrar o maior número. Isso é importante porque precisamos saber quantos dígitos binários (bits) são necessários para representar esse número.

2. **Calcule o número de bits**:
   - Determine quantos bits são necessários para representar o maior número. Por exemplo, se o maior número for 15, ele precisa de 4 bits (1111 em binário).

3. **Ordenação por cada bit**:
   - Para cada bit, do menos significativo (direita) ao mais significativo (esquerda):
     - Percorra todos os números na pilha principal (a_stack).
     - Para cada número, verifique o bit atual:
       - Se o bit for 1, mova o número para o final da pilha principal.
       - Se o bit for 0, mova o número para uma pilha auxiliar (b_stack).
     - Depois de verificar todos os números, mova todos os números da pilha auxiliar de volta para a pilha principal.

4. **Repetição para todos os bits**:
   - Repita o processo para cada bit até que todos os bits tenham sido verificados. Isso garante que os números estejam ordenados corretamente.

Este processo é repetido para cada bit do menor para o maior, garantindo que os números sejam ordenados corretamente no final.