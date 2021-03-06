/* -*- c++ -*- ----------------------------------------------------------
   LAMMPS - Large-scale Atomic/Molecular Massively Parallel Simulator
   http://lammps.sandia.gov, Sandia National Laboratories
   Steve Plimpton, sjplimp@sandia.gov

   Copyright (2003) Sandia Corporation.  Under the terms of Contract
   DE-AC04-94AL85000 with Sandia Corporation, the U.S. Government retains
   certain rights in this software.  This software is distributed under
   the GNU General Public License.

   See the README file in the top-level LAMMPS directory.
------------------------------------------------------------------------- */

#ifdef FIX_CLASS

FixStyle(fneb,FixFNEB)

#else

#ifndef LMP_FIX_FNEB_H
#define LMP_FIX_FNEB_H

#include "fix.h"

namespace LAMMPS_NS {

class FixFNEB : public Fix {
 public:
  double veng,plen,nlen;

  // for last replica relaxation
  double target_energy_delta;
  double target_energy;
  double relax_prefactor;

  int rclimber;
  double gradvnorm;

  FixFNEB(class LAMMPS *, int, char **);
  ~FixFNEB();
  int setmask();
  void init();
  void min_setup(int);
  void min_post_force(int);

 private:
  double kspring;
  void reset_final_replica();
  int ireplica,nreplica;
  int procnext,procprev;
  MPI_Comm uworld;

  char *id_pe;
  class Compute *pe;

  int nebatoms;
  double **xprev,**xnext;
  double **tangent;
};

}

#endif
#endif

/* ERROR/WARNING messages:

E: Illegal ... command

Self-explanatory.  Check the input script syntax and compare to the
documentation for the command.  You can use -echo screen as a
command-line option when running LAMMPS to see the offending line.

E: Potential energy ID for fix neb does not exist

Self-explanatory.

E: Atom count changed in fix neb

This is not allowed in a NEB calculation.

*/
