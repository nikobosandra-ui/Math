#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"

#include "print.h"

int main() {
    
    //  Initialisation 
    Point A = {1.0, 2.0};
    Point B = {4.0, 6.0};
    Vecteur V_test = {2.0, -1.0};

    print("--- Points initiaux ---");
    afficherPoint(A);
    afficherPoint(B);
    afficherVecteur(V_test);
    
    
    // Tests des opérations sur Vecteurs 
    print("\n--- Operations Vecteurs ---");
    
    Vecteur U_ab = creerVecteur(A, B);
    print("Vecteur U (B-A): ");
    afficherVecteur(U_ab);

    Vecteur W_add = additionVecteurs(U_ab, V_test);
    print("U + V_test: ");
    afficherVecteur(W_add);

    Vecteur W_sub = soustractionVecteurs(U_ab, V_test);
    print("U - V_test: ");
    afficherVecteur(W_sub);

    print("Produit Scalaire (U . V_test): " + std::to_string(produitScalaire(U_ab, V_test)));
    print("Determinant (U, V_test): " + std::to_string(determinant(U_ab, V_test)));
    print("Norme de U: " + std::to_string(norme(U_ab)));

    Vecteur U_norm = normaliser(U_ab);
    print("U normalise: ");
    afficherVecteur(U_norm);
    print("Norme de U normalise: " + std::to_string(norme(U_norm)));


    // Tests des transformations de Points 
    print("\n--- Transformations Points (sur A) ---");
    print("Point A initial: ");
    afficherPoint(A);

    // Translation
    Point A_trans = translation(A, V_test);
    print("A translate par V_test: ");
    afficherPoint(A_trans);

    // Scale
    Point A_scale = scale(A, 3.0);
    print("A scale par 3.0: ");
    afficherPoint(A_scale);

    // Rotation (90 degrés)
    double angle90rad = degresEnRadians(90.0);
    Point A_rot = rotation(A, angle90rad);
    print("A pivote de 90 deg: ");
    afficherPoint(A_rot);

    // Test utilitaire distance
    print("Distance entre A et B: " + std::to_string(distanceEntrePoints(A, B)));

    return 0;
}
