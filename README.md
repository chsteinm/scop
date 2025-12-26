# SCOP – Visualisation 3D en C++ / OpenGL

Ce projet est une implémentation du projet **SCOP** (école 42), dont l’objectif est d’afficher un objet 3D au format `.obj`.
Il s’agit à la fois d’un projet de rendu 3D temps réel et d’un terrain d’apprentissage pour OpenGL et le C++ orienté objet.

## Objectifs du projet

- Charger et parser des fichiers `.obj` simples (positions, normales, UV, indices).  
- Afficher l’objet en perspective dans une fenêtre, avec rotation autour de son axe principal.  
- Permettre les déplacements de l’objet sur les trois axes via les contrôles clavier/souris.  
- Afficher des couleurs par facette, puis appliquer une texture avec un toggle et une transition douce.

## Stack technique

- **Langage** : C++ (standard moderne).  
- **API graphique** : OpenGL 3.3+ core-profile mode
- **Fenêtre / contexte** : GLFW + GLAD

L’architecture suit les concepts classiques des moteurs graphiques simples : objets, maillages, shaders, caméras, etc.

## Ressources d’apprentissage

Une grande partie du projet est réalisée en suivant et en adaptant les tutoriels de **[learnopengl.com](https://learnopengl.com)** de Joey de Vries.
Ces tutoriels fournissent une introduction progressive à OpenGL moderne (pipeline, shaders, buffers, transformations, textures, lumière, etc.) que je réutilise ici pour construire un petit « moteur » minimal adapté au sujet SCOP.

Autres ressources utiles :

- Repo officiel des exemples LearnOpenGL : https://github.com/JoeyDeVries/LearnOpenGL 
- Divers exemples OpenGL C++ sur GitHub pour m’inspirer de la structure et des CMakeLists.

## État actuel du projet

- [x] Création de la fenêtre et du contexte OpenGL  
- [ ] Affichage d’un triangle / cube de test  
- [ ] Chargement d’un modèle `.obj` simple  
- [ ] Contrôles de caméra / transformation  
- [ ] Couleurs par facette  
- [ ] Texture toggle + transition  
- [ ] Nettoyage / refactor / documentation

Ce README sera mis à jour au fur et à mesure de l’avancement du projet.
