
//
// This source file is part of appleseed.
// Visit http://appleseedhq.net/ for additional information and resources.
//
// This software is released under the MIT license.
//
// Copyright (c) 2010 Francois Beaune
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in
// all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

#ifndef APPLESEED_STUDIO_MAINWINDOW_PROJECT_OBJECTINSTANCEITEM_H
#define APPLESEED_STUDIO_MAINWINDOW_PROJECT_OBJECTINSTANCEITEM_H

// appleseed.studio headers.
#include "mainwindow/project/entityitem.h"

// Qt headers.
#include <QList>
#include <QObject>

// Forward declarations.
namespace appleseed { namespace studio { class ItemBase; }}
namespace renderer  { class Assembly; }
namespace renderer  { class ObjectInstance; }
class QMenu;
class QString;
class QVariant;

namespace appleseed {
namespace studio {

class ObjectInstanceItem
  : public EntityItem
{
    Q_OBJECT

  public:
    ObjectInstanceItem(
        renderer::Assembly&         assembly,
        renderer::ObjectInstance&   object_instance);

    virtual QMenu* get_single_item_context_menu() const;

    virtual QMenu* get_multiple_items_context_menu(const QList<ItemBase*>& items) const;

    const renderer::Assembly& get_assembly() const;

  private slots:
    void slot_assign_material();
    void slot_assign_material_accepted(QString page_name, QString entity_name, QVariant data);
    void slot_unassign_material();

  private:
    renderer::Assembly&             m_assembly;
    renderer::ObjectInstance&       m_object_instance;

    void update_style();

    void assign_material(const size_t material_index);
    void unassign_material();
};

}       // namespace studio
}       // namespace appleseed

#endif  // !APPLESEED_STUDIO_MAINWINDOW_PROJECT_OBJECTINSTANCEITEM_H
