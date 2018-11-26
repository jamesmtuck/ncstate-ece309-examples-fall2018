namespace Core {
class L1Cache {};
class ALU {};
} // namespace Core

namespace MultiCore {
class Directory {};
} // namespace MultiCore

namespace MultiCore2 {
using namespace Core;
class L1Cache {};
class Directory {};
L1Cache x;
ALU y;
} // namespace MultiCore2

int main() {}
