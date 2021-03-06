
void TypeInfoOf<Reference>::gCollect(GC gc, RichNode from, StableNode& to) const {
  assert(from.type() == type());
  to.make<Reference>(gc->vm, gc, from.access<Reference>());
}

void TypeInfoOf<Reference>::gCollect(GC gc, RichNode from, UnstableNode& to) const {
  assert(from.type() == type());
  StableNode* stable = new (gc->vm) StableNode;
  to.make<Reference>(gc->vm, stable);
  stable->make<Reference>(gc->vm, gc, from.access<Reference>());
}

void TypeInfoOf<Reference>::sClone(SC sc, RichNode from, StableNode& to) const {
  assert(from.type() == type());
  to.make<Reference>(sc->vm, sc, from.access<Reference>());
}

void TypeInfoOf<Reference>::sClone(SC sc, RichNode from, UnstableNode& to) const {
  assert(from.type() == type());
  StableNode* stable = new (sc->vm) StableNode;
to.make<Reference>(sc->vm, stable);
stable->make<Reference>(sc->vm, sc, from.access<Reference>());
}

inline
class mozart::StableNode *  TypedRichNode<Reference>::dest() {
  return _self.access<Reference>().dest();
}
