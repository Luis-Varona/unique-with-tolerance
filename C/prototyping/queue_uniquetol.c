//
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include <string.h>
#include <math.h>
#include <sys/queue.h>

#include "../isapprox.h"
#include "../sortperm.h"
#include "../uniquetol.h"

//
struct node {
    int index;
    TAILQ_ENTRY(node) nodes;
};

UniqueTolArray uniquetol_var(double *arr, int n, UniqueTolArgs in) {
    double atol = in.atol ? in.atol : 1e-8;
    double rtol = in.rtol ? in.rtol : sqrt(nextafter(1, 2) - 1);
    char *occurrence = in.occurrence ? in.occurrence : "highest";
    
    int use_highest = strcmp(occurrence, "highest");
    int use_lowest = strcmp(occurrence, "lowest");
    
    if (use_highest != 0 && use_lowest != 0) {
        fprintf(stderr, "`occurrence` must be either `highest` or `lowest`");
        exit(1);
    }
    
    UniqueTolArray out;
    
    if (n == 0) {
        double arr_unique[0] = {};
        int indices_unique[0] = {};
        int inverse_unique[0] = {};
        int counts_unique[0] = {};
        
        out = (UniqueTolArray){
            .arr_unique = arr_unique,
            .indices_unique = indices_unique,
            .inverse_unique = inverse_unique,
            .counts_unique = counts_unique,
            .num_total = 0,
            .num_unique = 0
        };
    }
    else {
        int perm_sorted[n];
        sortperm(arr, perm_sorted, n);
        
        double arr_sorted[n];
        double c = arr[perm_sorted[0]];
        arr_sorted[0] = c;
        
        TAILQ_HEAD(head_s, node) head;
        TAILQ_INIT(&head);
        
        struct node *ind = malloc(sizeof(struct node));
        ind->index = 0;
        TAILQ_INSERT_TAIL(&head, ind, nodes);
        ind = NULL;
        int num_unique = 1;
        
        for (int i = 1; i < n; i++) {
            double next = arr[perm_sorted[i]];
            arr_sorted[i] = next;
            
            if (!isapprox(c, next, atol, rtol)) {
                c = next;
                ind = malloc(sizeof(struct node));
                ind->index = i;
                TAILQ_INSERT_TAIL(&head, ind, nodes);
                ind = NULL;
                num_unique++;
            }
        }
        
        double arr_unique[num_unique];
        int indices_unique[num_unique];
        int inverse_unique[n];
        int counts_unique[num_unique];
        int i = 0;
        
        TAILQ_FOREACH(ind, &head, nodes) {
            indices_unique[i] = ind->index;
            i++;
        }
        
        while (!TAILQ_EMPTY(&head)) {
            ind = TAILQ_FIRST(&head);
            TAILQ_REMOVE(&head, ind, nodes);
            free(ind);
            ind = NULL;
        }
        
        int index_last = indices_unique[num_unique - 1];
        int count_last = n - index_last;
        counts_unique[num_unique - 1] = count_last;
        
        for (int j = 0; j < count_last; j++) {
            inverse_unique[perm_sorted[index_last + j]] = num_unique - 1;
        }
        
        for (int i = 0; i < num_unique - 1; i++) {
            int index = indices_unique[i];
            int count = indices_unique[i + 1] - index;
            counts_unique[i] = count;
            
            for (int j = 0; j < count; j++) {
                inverse_unique[perm_sorted[index + j]] = i;
            }
        }
        
        if (use_highest == 0) {
            for (int i = 0; i < num_unique - 1; i ++) {
                indices_unique[i] = indices_unique[i + 1] - 1;
            }
            
            indices_unique[num_unique - 1] = n - 1;
        }
        
        for (int i = 0; i < num_unique; i++) {
            int index = perm_sorted[indices_unique[i]];
            arr_unique[i] = arr[index];
            indices_unique[i] = index;
        }
        
        out = (UniqueTolArray){
            .arr_unique = arr_unique,
            .indices_unique = indices_unique,
            .inverse_unique = inverse_unique,
            .counts_unique = counts_unique,
            .num_total = n,
            .num_unique = num_unique
        };
    }
    
    return out;
}