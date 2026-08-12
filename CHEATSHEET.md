# Git Cheatsheet — MyNDHUlab

Referans rapid pou jere kòd mwen yo sou GitHub.
Depo: https://github.com/7willA/MyNDHUlab

---

## 1. Workflow debaz la (85% nan tan an)

Kèlkeswa sa w fè — **ajoute**, **chanje**, oswa **efase** kòd — apre w fini, tape 3 kòmand sa yo:

```bash
git add .
git commit -m "yon ti mesaj sou sa w fè a"
git push
```

- `git add .` → pran TOUT chanjman yo (nouvo fichye, modifikasyon, efasman)
- `git commit -m "..."` → anrejistre yo lokalman ak yon mesaj
- `git push` → voye yo sou GitHub

> ⚠️ Toujou asire w ou nan bon dosye a anvan: `cd C:\Users\User\Desktop\MyNDHUlab`

---

## 2. Ki kòmand pou ki sitiyasyon

| Sa w vle fè | Kòmand |
|---|---|
| Ajoute yon nouvo fichye kòd | Kreye fichye a → 3 kòmand debaz yo |
| Chanje kòd ki egziste deja | Edite l → 3 kòmand debaz yo |
| Efase yon fichye | Efase l (File Explorer oswa `del non.c`) → 3 kòmand debaz yo |
| Chanje non yon fichye | Chanje non an → 3 kòmand debaz yo |

Nan tout ka yo, `git add .` wè chanjman an otomatikman.

---

## 3. Kòmand itil an plis

Wè sa ki chanje anvan w commit:

```bash
git status
```

Wè istwa commit yo:

```bash
git log --oneline
```

Pran dènye vèsyon an (si w travay sou plizyè òdinatè):

```bash
git pull
```

---

## 4. Règ enpòtan yo

1. Toujou fè **commit + push** apre w fini travay ou.
2. Si w edite sou yon lòt òdinatè tou, fè **`git pull`** anvan w kòmanse.
3. Fichye `.exe`, `.o`, `.dll` elatriye pa ale sou GitHub — `.gitignore` la deja okipe sa.

---

## 5. Chanje depo a Public (si w vle pataje l)

GitHub → depo a → **Settings** → **General** → **Danger Zone** → **Change visibility** → **Public**.
