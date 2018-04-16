#pragma once

namespace acow { namespace OS { namespace Windows {

//------------------------------------------------------------------------------
// XP
bool IsXP        () noexcept;
bool IsXP_OrLater() noexcept;

//------------------------------------------------------------------------------
// Vista
bool IsVista        () noexcept;
bool IsVista_OrLater() noexcept;

//------------------------------------------------------------------------------
// Seven
bool IsSeven        () noexcept;
bool IsSeven_OrLater() noexcept;

//------------------------------------------------------------------------------
// Eight
bool IsEight        () noexcept;
bool IsEight_OrLater() noexcept;

//------------------------------------------------------------------------------
// 10
bool IsTen        () noexcept;
bool IsTen_OrLater() noexcept;

} // namespace Windows
} // namespace OS
} // namespace acow