#include <linux/proc_fs.h>
#include <linux/seq_file.h>
#include <asm/uaccess.h>
#include <linux/hugetlb.h>
#include <linux/sched/signal.h>
#include <linux/sched.h>
#include <linux/module.h>
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/fs.h>

struct task_struct  *proceso;

#define BUFSIZE     150

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Listado de los procesos.");
MODULE_AUTHOR("Bryan Ordoñez");


static int escribir_archivo(struct seq_file * archivo, void *v) {
    seq_printf(archivo, " __________________________________________________\n");
    seq_printf(archivo, "| Lab. Sistemas Operativos 1                       |\n");
    seq_printf(archivo, "| Segundo Semestre 2019                            |\n");
    seq_printf(archivo, "| Bryan Otoniel Ordoñez Morales                    |\n");
    seq_printf(archivo, "| 2014-04243                                       |\n");
    seq_printf(archivo, "|                                                  |\n");
    seq_printf(archivo, "|    PRACTICA 2 (MODULO 2 - LISTA PROCESOS)        |\n");
    seq_printf(archivo, "|__________________________________________________|\n");
    seq_printf(archivo, "  Sistema Operativo: CentOS 7\n");
  
    for_each_process(proceso){            
		seq_printf(archivo, " PID   : \t%d \n", proceso->pid); 
        seq_printf(archivo, " Nombre: \t%s \n", proceso->comm); 
        seq_printf(archivo, " Estado: \t%ld \n", proceso->state);
        seq_printf(archivo, "---------------------------------\n"); 		 
	} 
    return 0;
}

static int al_abrir(struct inode *inode, struct  file *file) {
  return single_open(file, escribir_archivo, NULL);
}

static struct file_operations operaciones =
{        
    .open = al_abrir,
    .read = seq_read
};


static int iniciar(void)
{
    proc_create("cpu_201404243", 0, NULL, &operaciones);
    printk(KERN_INFO "Bryan Otoniel Ordoñez Morales\n");
    return 0;
}
 
static void salir(void)
{
    remove_proc_entry("cpu_201404243", NULL);
    printk(KERN_INFO "Sistemas Operativos 1\n");
}
 
module_init(iniciar);
module_exit(salir); 